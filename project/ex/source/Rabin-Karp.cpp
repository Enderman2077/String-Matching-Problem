#include<stdio.h>
#include<string.h>
#include<windows.h> 
FILE *fpr;
FILE *fpw;

int RK(char P[],int m,char T[],int n){//取RK算法的d=2 
	int Phash,Thash,d,i,j;
	Phash=0;
	Thash=0;
	d=1;
	for(i=1;i<=m-1;i++) d*=2;//计算d的值 
	for(i=0;i<m;i++){//计算P串和T串前m个字符构成的子串的hash值 
		Phash=Phash*2+(int)P[i];
		Thash=Thash*2+(int)T[i];
	}
	j=1;
	while(j<=n-m+1){//循环匹配 
		if(Phash==Thash&&memcmp(P,T+j-1,m)==0) return j;//匹配成功 
		Thash=(Thash-(int)T[j-1]*d)*2+(int)T[j+m-1];//计算移动后的T子串的hash值 
		j++;
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
	fpw=fopen("../output/Rabin-Karp/output.txt","a");
	for(i=0;i<32;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n);
	for(i=0;i<2;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	fscanf(fpr,"%c",&n);
	QueryPerformanceCounter(&time_start);//记录算法开始时的时间 
	res=RK(P,2,T,32);
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
	res=RK(P,3,T,256);
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
	res=RK(P,4,T,2048);
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
	res=RK(P,5,T,16384);
	QueryPerformanceCounter(&time_over);//记录算法结束时的时间 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//计算算法所用时间 
	fprintf(fpw,"文本串长度：2^14 模式串长度：5 首次匹配位置：%d 算法运行时间：%fns\n",res,run_time);
	for(i=0;i<131072;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n); 
	for(i=0;i<6;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	QueryPerformanceCounter(&time_start);//记录算法开始时的时间 
	res=RK(P,6,T,131072);
	QueryPerformanceCounter(&time_over);//记录算法结束时的时间 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//计算算法所用时间 
	fprintf(fpw,"文本串长度：2^17 模式串长度：6 首次匹配位置：%d 算法运行时间：%fns\n",res,run_time);
	fclose(fpr);
	fclose(fpw);
	return 0;
} 
