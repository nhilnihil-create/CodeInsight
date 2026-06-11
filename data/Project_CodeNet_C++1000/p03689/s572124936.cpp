// FUCKED UP FUCKED UP FUCKED UP FUCKED UP FUCKED UP
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=5e2+10, maxm=5e4+10, lg=21, mod=1e9+7, inf=1e18;

ll H,W,h,w,a[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>H>>W>>h>>w;
	if(H%h==0 && W%w==0) return cout<<"No",0;
	cout<<"Yes\n";
	if(H%h){for(int i=0;i<H;i++)if(i%h==0)for(int j=0;j<W;j++) a[i][j]=1000*h-1;}
	else if(W%w){for(int i=0;i<W;i++)if(i%w==0)for(int j=0;j<H;j++) a[j][i]=1000*w-1;}
	for(int i=0;i<H;i++,cout<<endl)for(int j=0;j<W;cout<<a[i][j++]-1000<<' ');
	
	return 0;
}




