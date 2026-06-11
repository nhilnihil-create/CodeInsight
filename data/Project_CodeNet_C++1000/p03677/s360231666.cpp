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
	int n,m;
	static int a[100010];
	static int under[100010];
	static int upper[100010];
	static ll int ruiseki[100010];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	ll int ans=0;
	int count=0;
	ll int temp=0;
	int temp1=0;
	int temp2=0;
	int max=0;
	int min=INFINT;
	int len=0;
	int sum=0;
	int ok=0;
	int ng=0;



	//データの読み込み


	scanf("%d %d",&n,&m);
//	scanf_s("%d %d",&n,&m);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
//		scanf_s("%d",&a[i]);
	}


	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

  	
	for(i=0;i<100010;i++){
		under[i]=0;
		upper[i]=0;
		ruiseki[i]=0;
	}

  
	temp=0;
	temp2=0;
	for(i=1;i<n;i++){
		under[a[i-1]]++;
		upper[a[i]]++;
		ruiseki[a[i]+1]=ruiseki[a[i]+1]+(a[i]-a[i-1]-1+m)%m;

		if(a[i-1]>a[i]){
			temp=temp+m-a[i-1];
			temp2++;
		}

	}

	ans=temp;

	for(i=2;i<=m;i++){
		temp2=temp2-upper[i-1];
		temp=temp+temp2-ruiseki[i];
		temp2=temp2+under[i-1];
		ans=max(ans,temp);
	}

	ans=-ans;
	for(i=1;i<n;i++){
		ans=ans+(a[i]-a[i-1]+m)%m;
	}

	//	printf("計算部分終了\n");

	//出力

	printf("%lld",ans);

	//	printf("結果の出力終了\n");


	return 0;
}

