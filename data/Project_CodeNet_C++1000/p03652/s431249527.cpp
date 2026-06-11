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
#define MOD 1000000007
#define MODANOTHER 998244353
#define PI acos(-1)

using namespace std;



int main(void)
{
	//変数の宣言
	int n,m,p;
	int a[310][310];
	int kyogi[310];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	ll int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;
	int ok,ng;



	//データの読み込み


	scanf("%d %d",&n,&m);
//	scanf_s("%d %d",&n,&m);

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
//			scanf_s("%d",&a[i][j]);
			a[i][j]--;
		}
	}


	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	ans=INFINT;

	for(k=0;k<m;k++){
		for(i=0;i<m;i++){
			kyogi[i]=0;
		}
		for(i=0;i<n;i++){
			kyogi[a[i][0]]++;
		}
		temp=0;
		for(i=0;i<m;i++){
			if(temp<kyogi[i]){
				temp=kyogi[i];
				temp2=i;
			}
		}

		ans=min(ans,temp);

		for(i=0;i<n;i++){
			flag=0;
			for(j=0;j<m-1;j++){
				if(flag==0&&a[i][j]==temp2){
					flag=1;
				}
				if(flag==1){
					a[i][j]=a[i][j+1];
				}
			}
		}
	}


	//	printf("計算部分終了\n");

	//出力


	printf("%d",ans);


	//	printf("結果の出力終了\n");


	return 0;
}

