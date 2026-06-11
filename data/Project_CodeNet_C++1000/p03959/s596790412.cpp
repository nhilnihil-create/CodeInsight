#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
const int mod=1000000007;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;cin >> n;
	vector<ll> t(n);
	vector<ll> a(n);
	rep(i,n) cin >> t.at(i);
	rep(i,n) cin >> a.at(i);
	vector<ll> b(n,1000000000000);
	vector<bool> c(n,true);
	c[0]=false;
	c[n-1]=false;
	if(n==1 && a[0]!=t[0]){
		cout << 0 << endl;
		return 0;
	}
	rep(i,n-1){
		if(t[i+1]>t[i]){
			c[i+1]=false;
			if(t[i+1]>a[i+1]){
				cout << 0 << endl;
				return 0;
			}
		}
		else if(t[i+1]==t[i]) b[i+1]=min(t[i+1],b[i+1]);
		else{
			cout << 0 << endl;
			return 0;
		}
	}
	rep(i,n-1){
		if(a[n-2-i]>a[n-1-i]){
			c[n-2-i]=false;
			if(a[n-2-i]>t[n-2-i]){
				cout << 0 << endl;
				return 0;
			}
		}
		else if(a[n-2-i]==a[n-1-i]) b[n-2-i]=min(b[n-2-i],a[n-2-i]);
		else{
			cout << 0 << endl;
			return 0;
		}
	}
	ll ans=1;
	rep(i,n){
		if(c[i]){
			ans*=b[i];
			ans%=mod;
		}
	}
	cout << ans << endl;
}