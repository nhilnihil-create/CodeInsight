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

bool check(string s){
    if (s.size() % 2 != 0) return false;
    int n = s.size();
    string t = s.substr(0, n/2);
    string u = s.substr(n/2);
    if (t == u) return true;
    else return false;
}


int main(){
    string s;
    cin >> s;
    int m = s.size();
    int ans = 0;
    for(int i = 1; i < m; i++){
        string t = s.substr(0, m-i);
        if (check(t)) ans = max(ans, m-i);
    }

    cout << ans << endl;

    return 0;
}
