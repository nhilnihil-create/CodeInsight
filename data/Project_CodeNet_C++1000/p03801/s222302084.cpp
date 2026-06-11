/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "billboard.inp"
#define FILE_OUT "billboard.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
#define pi 3.1415926535897
typedef long long ll;
//------------xúc xích normie tám muoi tám phan tram não----------//
ll n,m,k,cnt[100001],t,t1,i,j,minn=1e9,maxx,cur,lu,lv;
ll arr[100002];
string s;
ll cint,cval;
vector<ll> lis;
int main() {
//	ofile;
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
		lis.push_back(i);
	}
	sort(lis.begin(),lis.end(),[](ll a, ll b) {
		if (arr[a]-arr[b]) return (arr[a]>arr[b]);
		return (a<b);
	});
	for (i=0;i<n;i++)
	{
		if (i==0)
		{
			cint=lis[0];
			cval=0;
		}
		else
		{
			cval+=(-arr[lis[i]]+arr[lis[i-1]])*i;
			if (lis[i]<cint) 
			{
				cnt[cint]=cval;
				cint=lis[i];
				cval=0;
			}
		}
	}
	
			cval+=(arr[lis[i-1]])*i;
				cnt[cint]=cval;
				cint=lis[i];
				cval=0;
	for (i=0;i<n;i++) cout<<cnt[i+1]<<endl;
}