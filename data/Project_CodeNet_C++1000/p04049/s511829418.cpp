
//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <vector>
//#include <set>
//#include <map>
//#include <iostream>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12

using namespace std;

int m;
int come[2050];
vector<int> graph[2050];

void init(void){
	int i;
	for(i=0;i<2050;i++){
		come[i]=0;
	}
}

int evensearch(int a,int d){
	int i;
	int sum=1;
	if(come[a]==1) return 0;
	come[a]=1;
	if(d==m/2) return 1;

	for(i=0;i<graph[a].size();i++){
		sum=sum+evensearch(graph[a][i],d+1);
	}

	return sum;
}

int oddsearch(int a,int b,int d){
	int i;
	int sum=1;
	if(come[a]==1||a==b) return 0;
	come[a]=1;
	if(d==m/2) return 1;

	for(i=0;i<graph[a].size();i++){
		sum=sum+oddsearch(graph[a][i],b,d+1);
	}

//	printf("%d->%d\n",a,sum);
	return sum;
}

int main(void)
{
	//変数の宣言
	int n;
//	int m;
	int a[2050];
	int b[2050];
//
	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	ll int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;


	//データの読み込み
	scanf("%d %d",&n,&m);
//	scanf_s("%d %d",&n,&m);

	for(i=0;i<n-1;i++){
		scanf("%d %d",&a[i],&b[i]);
//		scanf_s("%d %d",&a[i],&b[i]);
		graph[a[i]].push_back(b[i]);
		graph[b[i]].push_back(a[i]);
	}

	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理
	if(m%2==0){
		for(i=1;i<=n;i++){
			init();
			temp=evensearch(i,0);
			ans=max(ans,temp);
		}
	}else{
		for(i=0;i<n-1;i++){
			init();
//			ans=max(ans,oddsearch(a[i],b[i],0)+oddsearch(b[i],a[i],0));
			temp=oddsearch(a[i],b[i],0);
			temp=temp+oddsearch(b[i],a[i],0);
			ans=max(ans,temp);

//			printf("(%d,%d)-->left->%d,right->%d\n",a[i],b[i],oddsearch(a[i],b[i],0),oddsearch(b[i],a[i],0));
		}
	}



	//	printf("計算部分終了\n");

	//出力

	printf("%d",n-ans);

	//	printf("結果の出力終了\n");


	return 0;
}

