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

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define swap(p,q) r=(p);(p)=(q);(q)=r
#define INF 1000000000000000000//10^18
#define INFINT 2000000001//2*10^9+1
#define MOD 1000000007//10^9+7
#define PI acos(-1)

using namespace std;


int main(void)
{
	//変数の宣言
	int n;
	int a[200010];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	ll int ans=0;
	int count=0;
	ll int temp,temp1,temp2;
	int max,min;
	int len;
	ll int sum=0;



	//データの読み込み


	scanf("%d",&n);
//	scanf_s("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
//		scanf_s("%d",&a[i]);
	}

	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	for(i=0;i<n;i++){
		sum=sum+a[i];
	}

	temp=0;
	ans=INF;
	for(i=0;i<n-1;i++){
		temp=temp+a[i];
		ans=min(ans,abs(sum-temp*2));
	}

	//	printf("計算部分終了\n");

	//出力

	printf("%lld",ans);

	//	printf("結果の出力終了\n");


	return 0;
}

