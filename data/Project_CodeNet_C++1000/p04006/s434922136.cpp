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
	ll ans=1000000000000000;
	ll n,x;
	cin >> n >> x;
	ll a[2010];
	FOR(i,n){
		cin >> a[i];
	}	
	ll v[2010][2010];

	FOR(i,n)v[i][0]=a[i];
	FOR(i,n){
		for(int j=1;j<n;j++){
			v[i][j]=min(v[i][(j-1)%n],a[(i+n-j)%n]);
		}
	}

	FOR(i,n){
		ll sum=0;
		FOR(j,n){
			sum+=v[j][i];
		}
		chmin(ans,sum+i*x);
	}

	cout << ans << endl;
	
	
}