#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int n;
int x[200000],y[200000];

vector<int>merge(vector<int>&a,vector<int>&b){
	vector<int>res(n);
	rep(i,n){
		res[i]=a[b[i]];
	}
	return res;
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&x[i]);
		y[i]=x[i];
		if(i)y[i]-=x[i-1];
	}
	int m;ll K;cin>>m>>K;
	vector<int>v(n);
	rep(i,n)v[i]=i;
	rep(i,m){
		int d;scanf("%d",&d);d--;
		swap(v[d],v[d+1]);
	}
	vector<int>ans(n);
	rep(i,n)ans[i]=i;
	while(K){
		if(K&1){
			ans=merge(ans,v);
		}
		v=merge(v,v);
		K>>=1;
	}
	ll sum=0;
	rep(i,n){
		sum+=y[ans[i]];
		printf("%lld\n",sum);
	}
}