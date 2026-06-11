#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int dfs ( int a, vector<vector<int>> &g ) {
    int cnt = 0;
    for ( auto tmp_num : g[a] ) {
        for ( auto tmp_num2 : g[tmp_num] ) {
            if ( a == tmp_num2 ) {
                ++cnt;
            }
        }
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i,n) {
        int tmp_a;
        cin >> tmp_a;
        --tmp_a;
        g[i].push_back(tmp_a);
    }
    int ans = 0;
    vector<bool> flg(n, false);
    rep(i,n) {
//        cout << dfs(i, g) << endl;
        ans += dfs(i, g);
    }
    cout << ans / 2 << endl;
    return 0;
}
