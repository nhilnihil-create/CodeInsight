#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int sa[100005], sb[100005], ta[100005], tb[100005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s, t;
	int q;
	cin >> s >> t >> q;
	int n = s.size();
	int m = t.size();
	rep(i,n){
		sa[i+1] = sa[i] + (s[i] == 'A');
		sb[i+1] = sb[i] + (s[i] == 'B');
	}
	rep(j,m){
		ta[j+1] = ta[j] + (t[j] == 'A');
		tb[j+1] = tb[j] + (t[j] == 'B');
	}
	rep(qi,q){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int A = (sa[b] - sa[a-1]) % 3;
		int B = (sb[b] - sb[a-1]) % 3;
		int C = (ta[d] - ta[c-1]) % 3;
		int D = (tb[d] - tb[c-1]) % 3;
		bool ok = false;
		rep(i,3){
			int AA = (A + i) % 3;
			int BB = (B + i) % 3;
			if(AA == C && BB == D){
				ok = true;
				break;
			}
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
