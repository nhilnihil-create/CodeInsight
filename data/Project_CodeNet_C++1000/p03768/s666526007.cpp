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

static int color[100010];
static int length[100010];
static vector<int> graph[100010];


int splat(int ver,int len,int col){
	int i;

	if(len<=length[ver]) return 0;
	if(color[ver]==0) color[ver]=col;

	length[ver]=len;

	if(len>0){
		for(i=0;i<graph[ver].size();i++){
			splat(graph[ver][i],len-1,col);
		}
	}

	return 0;
}

int main(void)
{
	//変数の宣言
	int n,m,q;
	static int a[100010];
	static int b[100010];
	static int v[100010];
	static int d[100010];
	static int c[100010];
//	vector<int> graph[100010];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;
	int ok,ng;
	int r;


	//データの読み込み


	scanf("%d %d",&n,&m);
//	scanf_s("%d %d",&n,&m);

	for(i=0;i<m;i++){
		scanf("%d %d",&a[i],&b[i]);
//		scanf_s("%d %d",&a[i],&b[i]);
		graph[a[i]].push_back(b[i]);
		graph[b[i]].push_back(a[i]);
	}

	scanf("%d",&q);
//	scanf_s("%d",&q);

	for(i=0;i<q;i++){
		scanf("%d %d %d",&v[i],&d[i],&c[i]);
//		scanf_s("%d %d %d",&v[i],&d[i],&c[i]);
	}

	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	for(i=1;i<=n;i++){
		color[i]=0;
		length[i]=-1;
	}

	for(i=q-1;i>=0;i--){
		splat(v[i],d[i],c[i]);
/*		for(j=1;j<=n;j++){
			printf("%d ",color[j]);
		}
		printf("\n");*/
	}
	

	//	printf("計算部分終了\n");

	//出力

	for(i=1;i<=n;i++){
		printf("%d\n",color[i]);
	}



	//	printf("結果の出力終了\n");


	return 0;
}

