//4.1��ɵ�һ�θ�ϰ

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
////��������������Ϣ
//struct PIX {
//	BYTE blue;
//	BYTE green;
//	BYTE red;
//};
//int padding(ImgInfo &imgInfo) {//������Ҫ������ֽ���
//	//(4-(width*3)%4)%4����ÿһ�е�
//	int supple = (imgInfo.bi.biWidth*imgInfo.bi.biBitCount + 31)/8;//��ಹ�����ֽڣ��Ǿ��ȶ�����
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
//	int newdiff = padding(newinfo);//�������ܻ���µ�����,��֤����Ĳ�����Сϸ��
//	newinfo.bi.biSizeImage = (DWORD)((newinfo.bi.biWidth * 3 + newdiff)*newinfo.bi.biHeight );
//	FILE *p;
//	//cout << newinfo.bi.biSizeImage << endl;
//	fopen_s(&p, save.c_str(), "wb");
//	//���Ըĳ���չ��
//	fwrite(&newinfo.bf, sizeof(BITMAPFILEHEADER), 1, p);
//	fwrite(&newinfo.bi, sizeof(BITMAPINFOHEADER), 1, p);
//	//д���µ��ļ�
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
//	fread(&imgInfo.bf, sizeof(BITMAPFILEHEADER),1, fp);//��ȡλͼ�ļ�ͷ
//	fread(&imgInfo.bi, sizeof(BITMAPINFOHEADER),1, fp);//��ȡλͼ��Ϣͷ
//	PIX*imgpix = new PIX[imgInfo.bi.biWidth*imgInfo.bi.biHeight];
//	int diff = padding(imgInfo);
//	//��ȡ������Ϣ
//	for (int i = 0; i < imgInfo.bi.biHeight; i++) {
//		fread((char*)imgpix + i * imgInfo.bi.biWidth * 3, 3, imgInfo.bi.biWidth, fp);
//		fseek(fp, diff, SEEK_CUR);//���������
//	}
//	fclose(fp);
//	rotation(imgpix, imgInfo, savepath);
//	delete[]imgpix;
//}
//

/*
ѧϰ��fread��fopen_s����ȡ�ͻ�ȡ����
*/