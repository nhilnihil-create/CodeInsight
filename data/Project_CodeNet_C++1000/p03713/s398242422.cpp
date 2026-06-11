#include<bits/stdc++.h>
#include <math.h>
#include <cmath>
#include <limits>
#include <iostream>
#include <assert.h>

#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=10000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	int x,y,cost;
};
int main(){

	ll h,w;
	ll t;
	cin>>h>>w;
	if(h%3==0||w%3==0){
		cout<<"0"<<endl;
		return 0;
	}
	t=min(h,w);
	ll t2=10000000001;
	for(int i=1; i<w; i++){
		ll s=min(i*h,h/2*(w-i));
		s=min(s,(h/2+h%2)*(w-i));
		ll s2=max(i*h,h/2*(w-i));
		s2=max((h/2+h%2)*(w-i),s2);
		t2=min(t2,s2-s);
	}
	t=min(t,t2);
	t2=10000000001;
	for(int i=1; i<h; i++){
		ll s=min(i*w,w/2*(h-i));
		s=min(s,(w/2+w%2)*(h-i));
		ll s2=max(i*w,w/2*(h-i));
		s2=max((w/2+w%2)*(h-i),s2);
		t2=min(t2,s2-s);
	}
	t=min(t,t2);
	cout<<t<<endl;
	return 0;

}


