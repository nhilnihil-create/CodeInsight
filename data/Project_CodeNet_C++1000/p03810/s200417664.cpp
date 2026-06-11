#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#define ll long long
using namespace std;
 
const int N=100005;
 
int n,os,js;
bool tag;
int a[N];

int gcd(int a,int b){
	if (!b) return a;
	else return gcd(b,a%b);
}

int dfs(int b){
	int i,g=0;
	js=os=0; tag=0;
	for (i=1;i<=n;i++){
		if (a[i]&1) a[i]--;
		g=gcd(g,a[i]);
	}
	for (i=1;i<=n;i++){
		a[i]/=g;
		if (a[i]&1){
			js++;
			if (a[i]==1) tag=1;
		}
		else os++;
	}
	if (os&1) return (!b);
	if (tag||js>1) return b;
	return dfs(b^1);
}
 
int main(){
	int i;
	scanf("%d",&n);
	tag=0;
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]&1){
			js++;
			if (a[i]==1) tag=1;
		}
		else os++;
	}
	if (os&1) printf("First\n");
	else{
		if (tag||js>1){
			printf("Second\n");
			return 0;
		}
		if (dfs(1)) printf("First\n");
		else printf("Second\n");
	}
	return 0;
}