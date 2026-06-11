#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MOD = 1000000007;
const int MN = 5010;

int dp[MN][MN];
int N;
string s;

inline void add(int &x, int y)
{
    x += y;
    if (x > MOD) x -= MOD;
}

int main() {
    cin >> N;
    cin >> s;

    dp[0][0] = 1;

    rep(i, N) {
    	rep(j, MN) if (dp[i][j] != 0) {
    		if (j) {
    			add(dp[i+1][j-1], dp[i][j]);
    		} else {
    			add(dp[i+1][j], dp[i][j]);
    		}

    		add(dp[i+1][j+1], dp[i][j] * 2);
    	}
    }

    int t = dp[N][s.size()];
    rep(i, s.size()) {
    	t = (ll)(MOD + 1) / 2 * t % MOD;
    }
    cout << t << endl;
    
    return 0;
}