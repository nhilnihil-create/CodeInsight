#include <bits/stdc++.h>
using namespace std;
const int N=20010;
const int C=30000;
int n;
int p[N];
int a[N],b[N];
int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; ++i) scanf("%d",&p[i]);
	for (int i=1; i<=n; ++i){
		a[i]=a[i-1]+C;
	}
	for (int i=n; i>=1; --i){
		b[i]=b[i+1]+C;
	}
	int la=0;
	for (int i=1; i<=n; ++i){
		int now=a[p[i]]+b[p[i]];
		if (now<=la){
			int k=la-now;
			a[p[i]]+=k+1;
		}
		la=a[p[i]]+b[p[i]];
	}
	for (int i=1; i<=n; ++i) cout<<a[i]<<" ";
	cout<<'\n';
	for (int i=1; i<=n; ++i) cout<<b[i]<<" ";
}