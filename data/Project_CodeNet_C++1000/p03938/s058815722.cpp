#include<bits/stdc++.h>
#define YY "YES\n"
#define NN "NO\n"
#define LL long long
using namespace std;

int n,m,ar[20001],a[20001],b[20001];

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for (int i=1;i<=n;i++){
		a[i]=i*n;
		b[i]=(n-i+1)*n;
	}
	for (int i=1;i<=n;i++){
		b[ar[i]]+=(i-1);
	}
	for (int i=1;i<n;i++) cout<<a[i]<<" ";
	cout<<a[n]<<"\n";
	for (int i=1;i<n;i++) cout<<b[i]<<" ";
	cout<<b[n]<<"\n";
}