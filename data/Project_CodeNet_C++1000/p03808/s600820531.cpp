#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll n,x[MAX],y[MAX],z,ttl,nw;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("output.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], z+=x[i];
    if(z%(n*(n+1)/2)!=0)return cout<<"NO\n",0;
    z/=n*(n+1)/2;
    rep(i,2,n){
    	if((z+x[i-1]-x[i])%n!=0)return cout<<"NO\n",0;
    	y[i-1] = (z+x[i-1]-x[i])/n;
	}
	if((z+x[n]-x[1])%n!=0)return cout<<"NO\n",0;
    y[n] = (z+x[n]-x[1])/n;
    rep(i,1,n)ttl+=y[i];
    if(ttl!=z)return cout<<"NO\n",0;
    nw = x[n]+z-n*y[n];
    rep(i,1,n){
    	if(nw!=x[i]||y[i]<0)return cout<<"NO\n",0;
    	nw+=z-n*y[i];
	}
	if(nw!=x[1])return cout<<"NO\n",0;
	cout<<"YES\n";
	return 0;
}