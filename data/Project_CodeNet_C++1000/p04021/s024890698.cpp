#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	map<int,bool> mp;
	rep(i,n){
		if(i % 2 == 0){
			mp[a[i]] = true;
		} else {
			mp[a[i]] = false;
		}
	}
	SORT(a);
	int ans = 0;
	rep(i,n){
		if(i%2 == 0){
			if(mp[a[i]]){
			} else {
				ans++;
			}
		} else {
			if(mp[a[i]]) ans++;
		}
	}
	cout << ans/2 << endl;
}
