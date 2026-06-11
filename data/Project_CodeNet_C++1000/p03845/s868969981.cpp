#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	int n;
	cin >> n;
	vi t(n);
	rep(i, n) cin >> t[i];
	int m;
	cin >> m;
	vi sub(m);
	rep(i, m){
		int p, x;
		cin >> p >> x;
		sub[i] = x - t[p-1];
	}

	rep(i, m){
		int ans = 0;
		rep(j, n){
			ans += t[j];
		}
		ans += sub[i];
		cout << ans << endl;
	}
    return 0;
}