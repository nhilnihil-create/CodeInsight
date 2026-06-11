#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int c[110000];
set<int>S;
int n;
int gcd(int a,int b){
	while(b){
		a%=b;swap(a,b);
	}
	return a;
}
int L[32][110000];
int R[32][110000];
int solve(int a,int b){
	int cur=0;
	long long cnt=0;
	for(int i=0;i<n;i++){
		cnt+=c[i]/a-1;
		cur=gcd(cur,c[i]/a);
		L[b][i+1]=cur;
	}
	cur=0;
	for(int i=n-1;i>=0;i--){
		cur=gcd(cur,c[i]/a);
		R[b][i]=cur;
	}
	for(int i=0;i<n;i++){
		if(c[i]/a==1)continue;
		int t=gcd(gcd(L[b][i],R[b][i+1]),c[i]/a-1);
		if(t==1&&cnt%2)return 1;
		if(t!=1&&solve(a*t,b+1)==0)return 1;
	}
	return 0;
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",c+i);
		n=a;
	int ret=solve(1,0);
	if(ret)printf("First\n");
	else printf("Second\n");
}
