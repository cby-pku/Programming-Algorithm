#include "geometry.h"

Geometry::Geometry() {}

Geometry::~Geometry() {}

void Geometry::add_line(Line line) {
	Layer& layer = layers_.back();
	layer.lines.push_back(line);
}

void Geometry::add_polygon(Polygon polygon) {
	Layer& layer = layers_.back();
	layer.polygons.push_back(polygon);
}

void Geometry::draw(Graphics& g) const {
	for (const Layer& layer : layers_) {
		for (const Line& line : layer.lines) {
			g.setThickness(line.thickness);
			g.setColor(line.color);
			g.drawLine(line.p1.x, line.p1.y, line.p2.x, line.p2.y);
		}
		for (const Polygon& polygon : layer.polygons) {
			g.setThickness(polygon.thickness);
			g.setColor(polygon.color);
			if (polygon.fill) {
				g.fillPolygon(polygon.points.data(), polygon.points.size());
			}
			else {
				g.drawPolygon(polygon.points.data(), polygon.points.size());
			}
		}
	}
}

void Geometry::save(const std::string& filename) const {
	std::ofstream ofs(filename, std::ios::binary);
	if (!ofs) {
		std::cerr << "Error: cannot open file " << filename << " for writing" << std::endl;
		return;
	}
	for (const Layer& layer : layers_) {
		int num_lines = layer.lines.size();
		ofs.write(reinterpret_cast<const char*>(&num_lines), sizeof(num_lines));
		for (const Line& line : layer.lines) {
			ofs.write(reinterpret_cast<const char*>(&line), sizeof(line));
		}
		int num_polygons = layer.polygons.size();
		ofs.write(reinterpret_cast<const char*>(&num_polygons), sizeof(num_polygons));
		for (const Polygon& polygon : layer.polygons) {
			int num_points = polygon.points.size();
			ofs.write(reinterpret_cast<const char*>(&num_points), sizeof(num_points));
			ofs.write(reinterpret_cast<const char*>(polygon.points.data()), num_points * sizeof(Point));
			ofs.write(reinterpret_cast<const char*>(&polygon.thickness), sizeof(polygon.thickness));
			ofs.write(reinterpret_cast<const char*>(&polygon.color), sizeof(polygon.color));
			ofs.write(reinterpret_cast<const char*>(&polygon.fill), sizeof(polygon.fill));
		}
	}
	ofs.close();
}

void Geometry::load(const std::string& filename) {
	std::ifstream ifs(filename, std::ios::binary);
	if (!ifs) {
		std::cerr << "Error: cannot open file " << filename << " for reading" << std::endl;
		return;
	}
	layers_.clear();
	while (ifs) {
		Layer layer;
		int num_lines;
		ifs.read(reinterpret_cast<char*>(&num_lines), sizeof(num_lines));
		for (int i = 0; i < num_lines; i++) {
			Line line;
			ifs.read(reinterpret_cast<char*>(&line), sizeof(line));
			layer.lines.push_back(line);
		}
		int num_polygons;
		ifs.read(reinterpret_cast<char*>(&num_polygons), sizeof(num_polygons));
		for (int i = 0; i < num_polygons; i++) {
			Polygon polygon;
			int num_points;
			ifs.read(reinterpret_cast<char*>(&num_points), sizeof(num_points));
			polygon.points.resize(num_points);
			ifs.read(reinterpret_cast<char*>(polygon.points.data()), num_points * sizeof(Point));
			ifs.read(reinterpret_cast<char*>(&polygon.thickness), sizeof(polygon.thickness));
			ifs.read(reinterpret_cast<char*>(&polygon.color), sizeof(polygon.color));
			ifs.read(reinterpret_cast<char*>(&polygon.fill), sizeof(polygon.fill));
			layer.polygons.push_back(polygon);
		}
		if (ifs) {
			layers_.push_back(layer);
		}
	}
	ifs.close();
}

int main() {
	Graphics g("Geometry");
	Geometry geo;
	Layer layer;
	Line line;
	Polygon polygon;
	char choice;

	std::cout << "Enter d to draw, s to save, l to load, or q to quit: " << std::endl;
	std::cin >> choice;

	while (choice != 'q') {
		switch (choice) {
		case 'd':
			std::cout << "Enter l for line, p for polygon, or b for new layer: " << std::endl;
			std::cin >> choice;
			switch (choice) {
			case 'l':
				std::cout << "Enter x,y coordinates for point 1: ";
				std::cin >> line.p1.x >> line.p1.y;
				std::cout << "Enter x,y coordinates for point 2: ";
				std::cin >> line.p2.x >> line.p2.y;
				std::cout << "Enter thickness and color (RGB) for line: ";
				std::cin >> line.thickness >> line.color.r >> line.color.g >> line.color.b;
				geo.add_line(line);
				break;
			case 'p':
				std::cout << "Enter number of points for polygon: ";
				int num_points;
				std::cin >> num_points;
				polygon.points.resize(num_points);
				for (int i = 0; i < num_points; i++) {
					std::cout << "Enter x,y coordinates for point " << i + 1 << ": ";
					std::cin >> polygon.points[i].x >> polygon.points[i].y;
				}
				std::cout << "Enter thickness and color (RGB) for polygon: ";
				std::cin >> polygon.thickness >> polygon.color.r >> polygon.color.g >> polygon.color.b;
				std::cout << "Fill polygon? (y/n): ";
				std::cin >> choice;
				polygon.fill = (choice == 'y');
				geo.add_polygon(polygon);
				break;
			case 'b':
				layer.lines.clear();
				layer.polygons.clear();
				geo.layers_.push_back(layer);
				break;
			default:
				std::cout << "Invalid choice!" << std::endl;
				break;
			}
			g.clear();
			geo.draw(g);
			break;
		case 's':
			std::cout << "Enter filename to save: ";
			std::string filename;
			std::cin >> filename;
			geo.save(filename);
			break;
		case 'l':
			std::cout << "Enter filename to load: ";
			std::cin >> filename;
			geo.load(filename);
			g.clear();
			geo.draw(g);
			break;
		default:
			std::cout << "Invalid choice!" << std::endl;
			break;
		}
		std::cout << "Enter d to draw, s to save, l to load, or q to quit: " << std::endl;
		std::cin >> choice;
	}

	return 0;
}