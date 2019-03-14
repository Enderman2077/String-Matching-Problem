#include<stdio.h>
#include<windows.h>
int NEXT[10];
FILE *fpr;
FILE *fpw;

void Next(char P[],int m){//����NEXT�����ֵ 
	int i,j;
	j=0;
	for(i=1;i<=m;i++){
		NEXT[i]=j;
		while(j>0&&P[i-1]!=P[j-1]) j=NEXT[j];
		j++;
	}
}

int KMP(char P[],int m,char T[],int n){//KMP�㷨 
	int i,j;
	j=1;
	Next(P,m);//���ú�������NEXT���� 
	for(i=0;i<n;i++){
		while(j>0&&T[i-1]!=P[j-1]) j=NEXT[j];//����NEXT�����ṩ����Ϣ����ƶ� 
		if(j==m) return i-m+1;//ƥ��ɹ� 
		j++;
	}
	return -1;//ƥ��ʧ�� 
}

int main(){
	double run_time;
	_LARGE_INTEGER time_start;//��ʼʱ�� 
	_LARGE_INTEGER time_over;//����ʱ�� 
	double dqFreq;//��ʱ��Ƶ�� 
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	char T[1000000],P[10],n;
	int i,res;
	fpr=fopen("../input/input.txt","r");
	fpw=fopen("../output/KMP/output.txt","a");
	for(i=0;i<32;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n); 
	for(i=0;i<2;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	fscanf(fpr,"%c",&n);
	QueryPerformanceCounter(&time_start);//��¼�㷨��ʼʱ��ʱ�� 
	res=KMP(P,2,T,32);
	QueryPerformanceCounter(&time_over);//��¼�㷨����ʱ��ʱ�� 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//�����㷨����ʱ�� 
	fprintf(fpw,"�ı������ȣ�2^5   ģʽ�����ȣ�2 �״�ƥ��λ�ã�%d �㷨����ʱ�䣺%fns\n",res,run_time);
	for(i=0;i<256;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n); 
	for(i=0;i<3;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	fscanf(fpr,"%c",&n);
	QueryPerformanceCounter(&time_start);//��¼�㷨��ʼʱ��ʱ�� 
	res=KMP(P,3,T,256);
	QueryPerformanceCounter(&time_over);//��¼�㷨����ʱ��ʱ�� 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//�����㷨����ʱ�� 
	fprintf(fpw,"�ı������ȣ�2^8   ģʽ�����ȣ�3 �״�ƥ��λ�ã�%d �㷨����ʱ�䣺%fns\n",res,run_time);
	for(i=0;i<2048;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n); 
	for(i=0;i<4;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	fscanf(fpr,"%c",&n);
	QueryPerformanceCounter(&time_start);//��¼�㷨��ʼʱ��ʱ�� 
	res=KMP(P,4,T,2048);
	QueryPerformanceCounter(&time_over);//��¼�㷨����ʱ��ʱ�� 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//�����㷨����ʱ�� 
	fprintf(fpw,"�ı������ȣ�2^11 ģʽ�����ȣ�4 �״�ƥ��λ�ã�%d �㷨����ʱ�䣺%fns\n",res,run_time);
	for(i=0;i<16384;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n); 
	for(i=0;i<5;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	fscanf(fpr,"%c",&n);
	QueryPerformanceCounter(&time_start);//��¼�㷨��ʼʱ��ʱ�� 
	res=KMP(P,5,T,16384);
	QueryPerformanceCounter(&time_over);//��¼�㷨����ʱ��ʱ�� 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//�����㷨����ʱ�� 
	fprintf(fpw,"�ı������ȣ�2^14 ģʽ�����ȣ�5 �״�ƥ��λ�ã�%d �㷨����ʱ�䣺%fns\n",res,run_time);
	for(i=0;i<131072;i++) fscanf(fpr,"%c",&T[i]);
	T[i]='\0';
	fscanf(fpr,"%c",&n); 
	for(i=0;i<6;i++) fscanf(fpr,"%c",&P[i]);
	P[i]='\0';
	QueryPerformanceCounter(&time_start);//��¼�㷨��ʼʱ��ʱ�� 
	res=KMP(P,6,T,131072);
	QueryPerformanceCounter(&time_over);//��¼�㷨����ʱ��ʱ�� 
	run_time=1000000*(time_over.QuadPart-time_start.QuadPart)/dqFreq;//�����㷨����ʱ�� 
	fprintf(fpw,"�ı������ȣ�2^17 ģʽ�����ȣ�6 �״�ƥ��λ�ã�%d �㷨����ʱ�䣺%fns\n",res,run_time);
	fclose(fpr);
	fclose(fpw);
	return 0;
}
