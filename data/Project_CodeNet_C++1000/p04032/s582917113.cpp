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

int main(){
    string s;
    cin >> s;
    unordered_map<char, vector<int>> vmp;

    int n = s.size();
    rep(i, n){
        vmp[s[i]].push_back(i);
    }
    for (auto v : vmp){
        vector<int> vtmp = v.second;
        int m = vtmp.size();
        if (m <= 1) continue;
        else {
            rep(j, m - 1) {
                if (vtmp[j+1] - vtmp[j] <= 2){
                    cout << vtmp[j]+1 << " " << vtmp[j+1]+1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << " " << -1 << endl;

    return 0;
}