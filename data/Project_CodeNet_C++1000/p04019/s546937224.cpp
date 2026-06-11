#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int num[4];

int main(){
    string s;
    cin >> s;
    rep(i, s.size()){
        if (s[i] == 'N') num[0] = 1;
        else if (s[i] == 'W') num[1] = 1;
        else if (s[i] == 'S') num[2] = 1;
        else if (s[i] == 'E') num[3] = 1;
    }

    if ((num[0] ^ num[2]) || (num[1] ^ num[3])) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}