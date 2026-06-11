#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int>V;
int cnt=0;long long T;

void ins(long long x){
	if(x==1)return;
	ins(x/2);
	V.push_back(++cnt);
	if(x&1)V.insert(V.begin(),++cnt);
}

int main(){
	scanf("%lld",&T);T++;
	ins(T);
	printf("%d\n",cnt<<1);
	for(int i=0;i<V.size();i++){
		printf("%d ",V[i]);
	}for(int i=1;i<=cnt;i++){
		printf("%d ",i);
	}return 0;
}