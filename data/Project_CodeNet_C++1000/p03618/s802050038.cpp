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

ll alph[26];

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    rep(i, n){
        int p = (s[i] -'a');
        alph[p]++;
    }

    ll res = 0;
    rep(i, 26){
        res += alph[i] * (alph[i] - 1) / 2;
    }
    cout << n * (n - 1) / 2 - res + 1 << endl;

    return 0;
}