#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);i++)
#define all(t) (t).begin(),(t).end()
#define MOD 1000000007
typedef long long ll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}
template <class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <class T> inline T LCM(T a,T b){return a*b/GCD(a,b);}

int main(){
	ll n,l,q;
	ll x[100010];
	cin >> n;
	vector<ll> v;
	v.push_back(-1);
	FOR(i,n){cin >> x[i];v.push_back(x[i]);}
	cin >> l >> q;
	v.push_back(10000000000000);
	ll p[100010][20];
	FOR(i,n){
		if(i==n-1){p[i][0]=n;break;}
		ll a=upper_bound(all(v),x[i]+l)-v.begin();
		p[i][0]=a-2;
	}
	p[n][0]=n;
	for(int i=1;i<=19;i++){
		FOR(j,n+1){
			p[j][i]=p[p[j][i-1]][i-1];
			
		}
	}
	
	
	FOR(i,q){
		ll a,b;
		cin >> a >> b;
		a--;b--;
		if(a>b)swap(a,b);
		ll ans=0;
		for(int i=19;i>=0;i--){
			if(p[a][i]<b){
				ans+=1<<i;
				a=p[a][i];
			}	
		}
		cout << ans+1 << endl;
	}
}