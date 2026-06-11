#include<bits/stdc++.h>

using namespace std;

#define int long long
#define x first
#define y second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define pb push_back
#define sz(a) (int)(a.size())

typedef long long ll;typedef vector<int> vi;
typedef pair<int,int> ii;typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 2e5+10;
int f[N],invf[N];

const long long mod = 1e9+7;
long long  powmod(long long a,long long p){
	ll ans=1;
	while(p){
		if(p&1) ans*=a;
		p/=2;a*=a; ans%=mod;a%=mod;
	}
	return ans;
}

long long mdinv(long long a){return powmod(a,mod-2); }


inline int ways(int a1,int b1,int a2,int b2){
	return f[(a2-a1+b2-b1)]*invf[a2-a1]%mod*invf[b2-b1]%mod;
}

signed main(){
	IOS
	int h,w,a,b;cin>>h>>w>>a>>b;
	f[0]=invf[0]=1;
	for(int i=1;i<N;i++){
		f[i]=f[i-1]*i%mod;
		invf[i]=mdinv(f[i]);
	}

	int ans= ways(1,1,h,w);
	for(int i=1;i<=b;i++){
		ans-=ways(1,1,h-a,i)*ways(h-a+1,i,h,w)%mod;
		ans%=mod;
	}
	ans+=mod;ans%=mod;
	cout<<ans;
}