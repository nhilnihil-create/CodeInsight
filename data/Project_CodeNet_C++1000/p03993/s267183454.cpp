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
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
		a[i]--;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if (a[a[i]] == i && a[i] > i)ans++;
	}
	cout << ans << endl;
	return 0;
}