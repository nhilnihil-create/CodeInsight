//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
int a[100005];
map<int,int>cnt;
int rem[100005],same[100005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		rem[a[i]%m]++;
		cnt[a[i]]++;
	}
	for(auto p:cnt){
		same[p.first%m]+=p.second/2;
	}
	int ans=0;
	if(m%2==0){
		ans+=rem[m/2]/2;
		rem[m/2]=0;
	}
	ans+=rem[0]/2;rem[0]=0;
	for(int i=1;i<=m/2;i++){
		int oppo=m-i;
		int add=min(rem[i],rem[m-i]);
		ans+=add;
//		cerr<<i<<" "<<oppo<<" "<<add<<endl;
		rem[i]-=add;
		rem[m-i]-=add;
	}
	for(int i=0;i<m;i++){
		int rest=min(rem[i]/2,same[i]);
		ans+=rest;
	}
	cout<<ans<<endl;
	return 0;
}