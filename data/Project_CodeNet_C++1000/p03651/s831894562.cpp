#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}

int main(){
	int n,k;
	int a[100010];
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int g=0,M=0;
	for(int i=0;i<n;i++){
		g=gcd(g,a[i]);
		chmax(M,a[i]);
	}
	if(k<=M&&k%g==0){
		puts("POSSIBLE");
	}
	else {
		puts("IMPOSSIBLE");
	}
}
