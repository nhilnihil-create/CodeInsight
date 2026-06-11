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
	int h,w,a,b;
	static int dp[510][510];

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


	scanf("%d %d %d %d",&h,&w,&a,&b);
//	scanf_s("%d %d %d %d",&h,&w,&a,&b);

/*	for(i=0;i<n;i++){
//		scanf("%d",&a);
		scanf_s("%d",&a);
	}*/


	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	if(h%a==0&&w%b==0){
		printf("No");
		return 0;
	}

	if(h%a!=0){
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(i%a<h%a){
					dp[i][j]=300000/(h%a);
				}else{
					dp[i][j]=-300500/(a-h%a);
				}
			}
		}
	}else{
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(j%b<w%b){
					dp[i][j]=300000/(w%b);
				}else{
					dp[i][j]=-300500/(b-w%b);
				}
			}
		}
	}

	//	printf("計算部分終了\n");

	//出力

	printf("Yes\n");

	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(j!=0)printf(" ");
			printf("%d",dp[i][j]);
		}
		printf("\n");
	}

	//	printf("結果の出力終了\n");


	return 0;
}

