//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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

int main(void)
{
	//変数の宣言
	int n;
	int a;
	int num[100];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp=0;
	int temp1=0;
	int temp2=0;
	int max=0;
	int min=INFINT;
	int len=0;
	int sum=0;
	int ok=0;
	int ng=0;



	//データの読み込み


	scanf("%d",&n);
//	scanf_s("%d",&n);

	for(i=0;i<100;i++){
		num[i]=0;
	}

	for(i=0;i<n;i++){
		scanf("%d",&a);
//		scanf_s("%d",&a);
		num[a]++;
		min=min(min,a);
		max=max(max,a);
	}


	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	if((max+1)/2!=min){
		printf("Impossible");
		return 0;
	}

	if(max%2==0){
		if(num[min]!=1){
			printf("Impossible");
			return 0;
		}
	}else{
		if(num[min]!=2){
			printf("Impossible");
			return 0;
		}
	}

	for(i=min+1;i<=max;i++){
		if(num[i]<2){
			printf("Impossible");
			return 0;
		}
	}

	//	printf("計算部分終了\n");

	//出力

	printf("Possible");

	//	printf("結果の出力終了\n");


	return 0;
}

