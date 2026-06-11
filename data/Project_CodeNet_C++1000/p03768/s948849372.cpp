/******************
*  Author: BD747  *
******************/
//dreamoon
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

#define SZ(X) ((int)(X).size())
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define RI(X) scanf("%d", &(X))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define PB push_back
#define MS1(X) memset((X), -1, sizeof((X)))
typedef long long LL;

const int MOD=1e9+7;
const int SIZE=1e6+10;
int input[SIZE][3],ma[SIZE],an[SIZE],bfs[SIZE];
vector<int> e[SIZE];

void go(int in[]){
	int x=in[0]-1,dd=in[1],v=in[2];
	if(dd<=ma[x])return;
	ma[x]=dd;
	bfs[0]=x;
	int rr=1;
	REP(i,rr){
		int x=bfs[i];
		if(!an[x])an[x]=v;
		if(!ma[x])continue;
		REP(j,SZ(e[x])){
			int y=e[x][j];
			int nd=ma[x]-1;
			if(nd>ma[y]){
				ma[y]=nd;
				bfs[rr++]=y;
			}
		}
	}
}

int main(){
	DRII(N,M);
	REP(i,M){
		DRII(x,y);x--;y--;
		e[x].PB(y);
		e[y].PB(x);
	}
	DRI(Q);
	REP(i,Q)REP(j,3)RI(input[i][j]);
	MS1(ma);
	for(int i=Q-1;i>=0;i--){
		go(input[i]);
	}
	REP(i,N)printf("%d\n",an[i]);
	return 0;
}