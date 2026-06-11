#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P2;
const int inf=1000000000;
int n,m;
ll d[200001]={};
ll s[200001]={};
ll add(int k,int s){
	while(k<2*m){
		d[k]+=s;
		k+=(k&-k);
	}
	return 0;
}
ll sum(int k){
	ll res=0;
	while(k>0){
		res+=d[k];
		k-=(k&-k);
	}
	return res;
}
int main() {
	cin>>n>>m;

	ll a1;
	cin>>a1;
	ll t=0;
	for(int i=1;i<n;++i){
		ll a2;
		cin>>a2;
		if(a2-a1>1){
			add(a1+2,1);
			add(a2+1,-a2+a1);
			add(a2+2,a2-a1-1);
		}
		if(a1-a2>0&&a2+m-a1>1){
			add(a1+2,1);
			add(a2+m+1,-a2-m+a1);
			add(a2+m+2,a2+m-a1-1);
		}
		if(a2>a1)t+=(a2-a1);
		if(a1>a2)t+=(a2+m-a1);
		a1=a2;
	}
	for(int i=1;i<2*m;++i){
		s[i]=s[i-1]+sum(i);
	}
	ll r=0;
	for(int i=1;i<m+1;++i){
		r=max(r,s[i]+s[m+i]);
	}
//	cout<<t;
	cout<<t-r<<endl;


	return 0;
}
