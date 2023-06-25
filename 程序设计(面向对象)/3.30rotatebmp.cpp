//4.1完成第一次复习

//#include<iostream>
//#include<cstdio>
//#include<stdio.h>
//#include<Windows.h>
//#include<vector>
//using namespace std;
////string imgpath="C:/Users/Dell/Desktop/hw14/1.bmp" ;
////string savepath = "C:/Users/Dell/Desktop/hw14/dest.bmp";
//typedef unsigned char BYTE;
//typedef struct {
//	BITMAPFILEHEADER  bf;
//	BITMAPINFOHEADER bi;
//}ImgInfo;
////单独处理像素信息
//struct PIX {
//	BYTE blue;
//	BYTE green;
//	BYTE red;
//};
//int padding(ImgInfo &imgInfo) {//计算需要补充的字节数
//	//(4-(width*3)%4)%4这是每一行的
//	int supple = (imgInfo.bi.biWidth*imgInfo.bi.biBitCount + 31)/8;//最多补三个字节，那就先都补上
//	supple -= supple % 4;
//	return supple - imgInfo.bi.biWidth*imgInfo.bi.biBitCount /8;
//}
//void rotation( const PIX*input, ImgInfo&sinfo,string save) {
//	long new_height = sinfo.bi.biWidth;
//	long new_width = sinfo.bi.biHeight;/*
//	cout << new_width << endl;
//	cout << sinfo.bi.biHeight << endl;*/
//	ImgInfo newinfo;
//
//	newinfo.bf = sinfo.bf;
//	newinfo.bi = sinfo.bi;
//
//	newinfo.bi.biHeight = (DWORD)new_height;
//	newinfo.bi.biWidth = (DWORD)new_width;
//	int newdiff = padding(newinfo);//这样才能获得新的行列,保证下面的不出错，小细节
//	newinfo.bi.biSizeImage = (DWORD)((newinfo.bi.biWidth * 3 + newdiff)*newinfo.bi.biHeight );
//	FILE *p;
//	//cout << newinfo.bi.biSizeImage << endl;
//	fopen_s(&p, save.c_str(), "wb");
//	//可以改成扩展名
//	fwrite(&newinfo.bf, sizeof(BITMAPFILEHEADER), 1, p);
//	fwrite(&newinfo.bi, sizeof(BITMAPINFOHEADER), 1, p);
//	//写入新的文件
//	PIX*target = new PIX[new_height*new_width];
//	for (int i = 0; i < new_height; i++) {
//		for (int j = 0; j < new_width; j++) {
//			*(target + i * new_width + j) = *(input + j * new_height + new_height - i - 1);
//		}
//	}
//	char s = '0';
//	for (int i = 0; i < new_height; i++) {
//		fwrite((char*)target + i * new_width * 3, 3, new_width, p);
//		fwrite(&s, 1,newdiff, p);
//	}
//	fclose(p);
//	delete[]target;
//
//}
//int main(int argc,char*argv[]) {
//	ImgInfo imgInfo;
//	//cout << argv[0] << endl;
//	//cout << argv[1] << endl;
//	string imgpath(argv[1]);
//	string savepath(argv[2]);
//	FILE*fp;
//	fopen_s(&fp, imgpath.c_str(), "rb");
//	if (fp == NULL) {
//		cout << "fail" << endl; exit(0);
//	}
//	fread(&imgInfo.bf, sizeof(BITMAPFILEHEADER),1, fp);//读取位图文件头
//	fread(&imgInfo.bi, sizeof(BITMAPINFOHEADER),1, fp);//读取位图信息头
//	PIX*imgpix = new PIX[imgInfo.bi.biWidth*imgInfo.bi.biHeight];
//	int diff = padding(imgInfo);
//	//读取像素信息
//	for (int i = 0; i < imgInfo.bi.biHeight; i++) {
//		fread((char*)imgpix + i * imgInfo.bi.biWidth * 3, 3, imgInfo.bi.biWidth, fp);
//		fseek(fp, diff, SEEK_CUR);//跳过补充的
//	}
//	fclose(fp);
//	rotation(imgpix, imgInfo, savepath);
//	delete[]imgpix;
//}
//

/*
学习用fread和fopen_s来读取和获取数据
*/