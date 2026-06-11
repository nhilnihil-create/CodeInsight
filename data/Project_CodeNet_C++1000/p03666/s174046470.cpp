//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <bitset>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000000000//10^18
#define INFINT 2000000001//2*10^9+1
#define MOD 1000000007
#define MODANOTHER 998244353
#define PI acos(-1)

using namespace std;

struct bangumi_t{
	int s;
	int t;
	int c;
};

int compare_channel(const void *a, const void *b) {//降順と昇順あってる？？
	struct bangumi_t *A = (struct bangumi_t *)a;
	struct bangumi_t *B = (struct bangumi_t *)b;
	if(A->c - B->c >0){
		return 1;
	}else if(A->c - B->c <0){
		return -1;
	}else{
		return 0;
	}
}


int main(void)
{
	//変数の宣言
	ll int n,a,b,c,d;

	//よく使う変数
	ll int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	ll int temp=0;
	int temp1=0;
	int temp2=0;
	int temp3=0;
	int max=0;
	int min=INFINT;
	int len=0;
	int sum=0;
	int ok=0;
	int ng=0;
	char dummy;
	char stemp[11];
	
	//データの読み込み


	scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
//	scanf_s("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);

//	scanf("%s",&s);
//	scanf_s("%s",&s,5);


/*	for(i=0;i<n;i++){
//		scanf("%d %d %d",&temp1,&temp2,&temp3);
		scanf_s("%d %d %d",&temp1,&temp2,&temp3);

		bangumi[i].s=temp1;
		bangumi[i].t=temp2;
		bangumi[i].c=temp3;
	}*/


/*	for(i=0;i<n;i++){
//		scanf("%d",&c[i]);
		scanf_s("%d",&c[i]);
		d[i]=0;
	}*/


	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

//	clock_t start=clock();

	flag=0;
	for(i=0;i<n;i++){
		if(i*c-(n-i-1)*d<=b-a&&b-a<=i*c-(n-i-1)*d+(d-c)*(n-1)) flag=1;
	}


//	clock_t end=clock();

	//	printf("計算部分終了\n");

	//出力
	if(flag==0){
		printf("NO");
	}else{
		printf("YES");
	}

//	printf("time=%lf",(double)(end-start)/CLOCKS_PER_SEC);
	//	printf("結果の出力終了\n");

	return 0;
}

