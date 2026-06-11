#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int n;cin>>n;
	vector<ll> a(n);
	vector<ll> s(n + 1,0);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	sort(ALL(a));
	ll ans = 1;
	for(int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i];
	}
	for(int i = n - 1; i >= 1 ; i--) {
		if (2 * s[i] >= a[i]){
			ans++;
		}
		else{
			break;
		}
	}
	cout << ans << endl;
	return 0;
}