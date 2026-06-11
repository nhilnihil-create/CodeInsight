#include<bits/stdc++.h>
using namespace std;


int a[100001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,L;
	cin>>n>>L;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int x=0;
	for(x=1;x<n;x++)
		if(a[x]+a[x+1]>=L)
			break;
	if(x==n){
		cout<<"Impossible"<<endl;
	}
	else{
		cout<<"Possible"<<endl;
		for(int i=1;i<x;i++)
			cout<<i<<'\n';
		for(int i=n-1;i>x;i--)
			cout<<i<<'\n';
		cout<<x<<'\n';
	}
}
