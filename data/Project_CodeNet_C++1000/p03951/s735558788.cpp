#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int solve(int n, string &s, string &t){
    int res = 0;
    rep(i, n){
        int cnt = 0;

        string u = s.substr(n-i-1), v = t.substr(0, i+1);
        if(u == v) {
            res = max(res, i+1);
        }

        res = max(res, cnt);
    }

    return 2 * n - res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    string s, t;
    cin >> n >> s >> t;

    cout << solve(n, s, t) << endl;

    return 0;
}

