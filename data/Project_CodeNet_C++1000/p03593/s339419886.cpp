#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(x) (x).begin(),(x).end()
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
	int n,m;cin>>n>>m;
	vector<char>a;
	rep(i,n)rep(j,m){char b;cin>>b;a.PB(b);}
	sort(all(a));
	map<char,int>b;
	rep(i,a.size())b[a[i]]++;
	a.erase(unique(all(a)),a.end());
	int cnt4=0;
	rep(i,a.size()){
		while(b[a[i]]>=4){
			cnt4++;
			b[a[i]]-=4;
		}
	}
	int cnt2=0;
	rep(i,a.size()){
		while(b[a[i]]>=2){
			cnt2++;
			b[a[i]]-=2;
		}
	}
	int cnt1=0;
	rep(i,a.size()){
		while(b[a[i]]>=1){
			cnt1++;
			b[a[i]]--;
		}
	}
	if(n%2==0&&m%2==0){
		if(cnt4==n*m/4)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	if(n%2==0&&m%2==1){
		while(cnt4>(n/2)*(m-1)/2){
			cnt4--;
			cnt2+=2;
		}
		if(cnt4==(n/2)*(m-1)/2&&cnt2==n/2)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	if(n%2==1&&m%2==0){
		while(cnt4>(m/2)*(n-1)/2){
			cnt4--;
			cnt2+=2;
		}
		if(cnt4==(m/2)*(n-1)/2&&cnt2==m/2)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	if(n%2==1&&m%2==1){
		while(cnt4>(m-1)*(n-1)/4){
			cnt4--;
			cnt2+=2;
		}
		if(cnt4==(m-1)*(n-1)/4&&cnt2==(m-1)/2+(n-1)/2&&cnt1==1){
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
}
