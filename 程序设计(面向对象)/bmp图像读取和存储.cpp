////数据存储
//#include<iostream>
//#include<vector>
//#include<cstdio>
//#include<Windows.h>
//#include<string>
//using namespace std;
//string imgpath = "C:/Users/Dell/Desktop/hw14/1.bmp";
//string savepath = "C:/Users/Dell/Desktop/hw14/save.bmp";
//
//typedef struct {
//	BITMAPFILEHEADER  bf;
//	BITMAPINFOHEADER bi;
//	vector<vector<char>>imgData;
//}ImgInfo;
//
////使用fread函数实现bmp读取
//ImgInfo readBmp(string imgPath) {
//	ImgInfo imgInfo;
//	FILE*fp;
//	fopen_s(&fp, imgPath.c_str(), "rb");
//	if (fp == NULL) {
//		cout << "fail" << endl; exit(0)
//			;
//	}
//	fread(&imgInfo.bf, sizeof(BITMAPFILEHEADER), 1, fp);//读取位图文件头
//	fread(&imgInfo.bi, sizeof(BITMAPINFOHEADER), 1, fp);//读取位图信息头
//	//用fseek函数读取bfOffBits字段，对图像像素数据进行定位，来获取像素数据信息，并存放在二维数组中
//	fseek(fp, imgInfo.bf.bfOffBits, 0);
//	buf = (char*)malloc(imgInfo.bi.biWidth*imgInfo.bi.biHeight * 3);
//	//因为是RGB三色
//	fread(buf, 1, imgInfo.bi.biWidth*imgInfo.bi.biHeight * 3, fp);
//	p = buf;//获取初始位置头
//	vector<vector<char>>imgData;
//	for (int y = 0; y < imgInfo.bi.biHeight; y++) {
//		for (int x = 0; x < imgInfo.bi.biWidth; x++) {
//			vector<char>vRGB;
//			vRGB.push_back(*(p++));//B
//			vRGB.push_back(*(p++));//G
//			vRGB.push_back(*(p++));//R
//			//排除补0情况
//			if (x == imgInfo.bi.biWidth - 1) {
//				for (int k = 0; k < imgInfo.bi.biWidth % 4; k++)p++;
//			}
//			imgData.push_back(vRGB);
//		}
//	}
//	fclose(fp);
//	imgInfo.imgData = imgData;
//	return imgInfo;
//}
//
////位图文件的保存，可以在这里是实现翻转
//ImgInfo rotate(ImgInfo imgInfo) {
//	ImgInfo rotate_img;
//	int new_width = imgInfo.bi.biHeight;
//	int new_height = imgInfo.bi.biWidth;
//	vector<vector<char>>rimgData;
//	vector<char>vRGB;
//	cout << "error1" << endl;
//	int p = 0;
//	for (int i = 0; i < new_height; i++) {
//		vRGB.clear();
//		for (int j = 0; j < new_width * 3;j+=3) {
//
//			for (int k = 0; k < 3; k++) {
//				cout << imgInfo.imgData[0][0] << endl;
//				//vRGB.push_back( imgInfo.imgData([j/3][(new_height - i - 1) * 3 + k]);
//				
//			}
//		}
//		rimgData.push_back(vRGB);
//	}
//	cout << "error" << endl;
//	rotate_img.imgData = rimgData;
//	return rotate_img;
//}
//int getDiff(ImgInfo imgInfo) {
//	int DataSizePerLine = (imgInfo.bi.biWidth*imgInfo.bi.biBitCount + 31) >> 3;//除以8
//	DataSizePerLine -= DataSizePerLine % 4;
//	return DataSizePerLine - (imgInfo.bi.biWidth*imgInfo.bi.biBitCount )>> 3;
//}
//void saveBitmap(ImgInfo imgInfo) {
//	FILE *fpw;
//	fopen_s(&fpw, savepath.c_str(), "wb");
//	int new_width = imgInfo.bi.biHeight;
//	int new_height = imgInfo.bi.biWidth;
//	int newdiff = getDiff(imgInfo);
//	int new_size = (new_width * 3 + newdiff)*new_height;
//	imgInfo.bi.biHeight = new_height;
//	imgInfo.bi.biWidth = new_width;//更改长宽位置
//	imgInfo.bi.biSizeImage = new_size;//更改图片尺寸
//	fwrite(&imgInfo.bf, sizeof(BITMAPFILEHEADER), 1, fpw);
//	fwrite(&imgInfo.bi, sizeof(BITMAPINFOHEADER), 1,  fpw);
//
//	int size = imgInfo.bi.biWidth*imgInfo.bi.biHeight;
//	for (int i = 0; i < size; i++) {
//		fwrite(&imgInfo.imgData.at(i).at(0), 1, 1, fpw);//B，这是取模啊
//		fwrite(&imgInfo.imgData.at(i).at(1), 1, 1, fpw);//G
//		fwrite(&imgInfo.imgData.at(i).at(2), 1, 1, fpw);//R
//		//填充0字符
//		if (i%imgInfo.bi.biWidth == imgInfo.bi.biWidth - 1) {
//			char ch = '0';
//			for (int j = 0; j < imgInfo.bi.biWidth % 4; j++) {//补成四的倍数
//				fwrite(&ch, 1, 1, fpw);
//			}
//		}
//
//	}
//	fclose(fpw);
//	cout << "已保存至" << savepath << endl;
//}
//int main() {
//	ImgInfo imgInfo = readBmp(imgpath);
//	ImgInfo rotate_img = rotate(imgInfo);
//	saveBitmap(rotate_img);
//	return 0;
//}
//
////尺寸也会变