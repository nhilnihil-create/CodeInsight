#include<bits/stdc++.h>
using namespace std;
int a[100000];

vector<int> nxt(vector<int> x,vector<int> y){
	vector<int> res(x.size());
	for(int i=0;i<x.size();i++)
		res[i]=x[y[i]];
	return res;
}

vector<int> power(vector<int> x,long long int k){
	vector<int> res(x.size());
	for(int i=0;i<res.size();i++)
		res[i]=i;
	while(k){
		if(k&1)	res=nxt(res,x);
		x=nxt(x,x);
		k>>=1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int> x(n-1);
	for(int i=0;i<n-1;i++)
		x[i]=i;
	int m;
	long long int k;
	cin>>m>>k;
	for(int i=1,j;i<=m;i++){
		cin>>j;
		swap(x[j-2],x[j-1]);
	}
	x=power(x,k);
	long long int cur=a[0];
	cout<<cur<<'\n';
	for(int i=0;i<n-1;i++){
		cur+=a[x[i]+1]-a[x[i]];
		cout<<cur<<'\n';
	}
}
