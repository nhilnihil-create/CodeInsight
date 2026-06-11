#include "bits/stdc++.h"
using namespace std;
#define Rep(i,n) for(int i=0;i<(int)(n);i++)
#define For(i,n1,n2) for(int i=(int)(n1);i<(int)(n2);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define RREP(i,n) for(ll i=((ll)(n)-1);i>=0;i--)
#define FOR(i,n1,n2) for(ll i=(ll)(n1);i<(ll)(n2);i++)
#define put(a) cout<<a<<"\n"
#define all(a)  (a).begin(),(a).end()
#define SORT(a) sort((a).begin(),(a).end())
#define oorret 0
#define oor(x) [&](){try{x;} catch(const out_of_range& oor){return oorret;} return x;}()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
template<typename T1, typename T2> inline bool chmin(T1& a, T2 b) { if (a > b) { a = b; return 1; }return 0; }
template<typename T1, typename T2> inline bool chmax(T1& a, T2 b) { if (a < b) { a = b; return 1; }return 0; }

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<string>> s(h, vector<string>(w));
	REP(i, h) {
		REP(j, w) {
			cin >> s[i][j];
		}
	}
	int resh=0, resw=0;
	REP(i, h) {
		REP(j, w) {
			if (s[i][j] == "snuke") {
				resh = i;
				resw = j;
				break;
			}
		}
	}
	cout << (char)(resw + 'A' )<< resh + 1;
	return 0;
}