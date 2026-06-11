#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,A[110000];
const string ans[2]={"First","Second"};
void solve(int k){
	long long tot=0; int pd=0,where=0,num=0;
	for (int i=1;i<=n;i++){
		tot+=A[i]; if (A[i]==1) pd=1;
		if (A[i]&1) num++,where=i;
	}
	if (pd){
		if ((tot-n)&1) cout<<ans[k]<<endl; else cout<<ans[k^1]<<endl;
		exit(0);
	}
	if ((tot-n)&1){
		if (n==2&&num==2){
			A[1]--; 
		} else {
			cout<<ans[k]<<endl; exit(0);
		}
	} else {
		if (num==1){
			A[where]--;
		} else {
			cout<<ans[k^1]<<endl; exit(0);
		}
	}
	int d=0;
	for (int i=1;i<=n;i++) d=__gcd(d,A[i]);
	for (int i=1;i<=n;i++) A[i]/=d;
	solve(k^1);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	solve(0);
	return 0;
}