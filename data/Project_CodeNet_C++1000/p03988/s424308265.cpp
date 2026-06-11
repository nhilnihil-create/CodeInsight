#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

/*
*/

bool ok=true;
ll n,node[110]={},mi=1e9,ma=-1;  // 最遠距離がindexの点

void init(){
	cin>>n;
	rep(i,n){
		ll a;
		cin>>a;
		node[a]++;
		mi=min(mi,a);
		ma=max(ma,a);
	}
}

int main(void){
	init();
	if(mi != (ma+1)/2)ok=false;
	if(ma%2==0 && node[mi]!=1)ok=false;
	if(ma%2==1 && node[mi]!=2)ok=false;
	reg(i,mi+1,ma)if(node[i]<2)ok=false;
	cout<<(ok?"Possible":"Impossible")<<endl;
	return 0;
}