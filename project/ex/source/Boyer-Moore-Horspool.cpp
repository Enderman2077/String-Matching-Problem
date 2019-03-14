#include<stdio.h>
#include<string.h>
#include<windows.h>
int Bc[10];
FILE *fpr;
FILE *fpw;

void PreBc(char P[],int m){//计算Bc数组的值 
	int i;
	for(i=1;i<=6;i++) Bc[i]=m;
	for(i=1;i<=m-1;i++) Bc[P[i-1]-64]=m-i;
}

int BMH(char P[],int m,char T[],int n){//取RK算法的d=2 
	int i,j;
	char c;
	PreBc(P,m);//调用函数计算Bc数组 
	j=1;
	while(j<=n-m+1){//循环匹配 
		c=T[j+m-2]; 
		if(P[m-1]==c&&memcmp(P,T+j-1,m)==0) return j;//匹配成功 
		j+=Bc[c-64];//根据Bc数组提供的信息向后移动 
	}
	return -1;//匹配失败 
}

int main(){
	double run_time;
	_LARGE_INTEGER time_start;//开始时间 
	_LARGE_INTEGER time_over;//结束时间 
	double dqFreq;//计时器频率 
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	char T[1000000],P[10],n;
	int i,res;
	fpr=fopen("../input/input.txt","r");
	fpw=fopen("../output/Boyer-Moore-Horspool/output.txt","a");
	for(i=0;i<32;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n); 
	for(i=0;i<2;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	fscanf(fpr,"%c",&n);
	QueryPerformanceCounter(&time_start);//记录算法开始时的时间 
	res=BMH(P,2,T,32);
	QueryPerformanceCounter(&time_over);//记录算法结束时的时间 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//计算算法所用时间 
	fprintf(fpw,"文本串长度：2^5   模式串长度：2 首次匹配位置：%d 算法运行时间：%fns\n",res,run_time);
	for(i=0;i<256;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n); 
	for(i=0;i<3;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	fscanf(fpr,"%c",&n);
	QueryPerformanceCounter(&time_start);//记录算法开始时的时间 
	res=BMH(P,3,T,256);
	QueryPerformanceCounter(&time_over);//记录算法结束时的时间 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//计算算法所用时间 
	fprintf(fpw,"文本串长度：2^8   模式串长度：3 首次匹配位置：%d 算法运行时间：%fns\n",res,run_time);
	for(i=0;i<2048;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n);
	for(i=0;i<4;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	fscanf(fpr,"%c",&n);
	QueryPerformanceCounter(&time_start);//记录算法开始时的时间 
	res=BMH(P,4,T,2048);
	QueryPerformanceCounter(&time_over);//记录算法结束时的时间 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//计算算法所用时间 
	fprintf(fpw,"文本串长度：2^11 模式串长度：4 首次匹配位置：%d 算法运行时间：%fns\n",res,run_time);
	for(i=0;i<16384;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n); 
	for(i=0;i<5;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	fscanf(fpr,"%c",&n);
	QueryPerformanceCounter(&time_start);//记录算法开始时的时间 
	res=BMH(P,5,T,16384);
	QueryPerformanceCounter(&time_over);//记录算法结束时的时间 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//计算算法所用时间 
	fprintf(fpw,"文本串长度：2^14 模式串长度：5 首次匹配位置：%d 算法运行时间：%fns\n",res,run_time);
	for(i=0;i<131072;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n); 
	for(i=0;i<6;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	QueryPerformanceCounter(&time_start);//记录算法开始时的时间 
	res=BMH(P,6,T,131072);
	QueryPerformanceCounter(&time_over);//记录算法结束时的时间 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//计算算法所用时间 
	fprintf(fpw,"文本串长度：2^17 模式串长度：6 首次匹配位置：%d 算法运行时间：%fns\n",res,run_time);
	fclose(fpr);
	fclose(fpw);
	return 0;
}
