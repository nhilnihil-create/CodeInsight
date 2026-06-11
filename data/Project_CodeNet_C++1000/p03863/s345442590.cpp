#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] == s[n-1] && n % 2 == 0) cout << "First" << endl;
    else if (s[0] != s[n-1] && n % 2 == 1) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
