#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> to[200005];

int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i, 0, n){
        int ans = 0;
        for(int u : to[i]) ans++;
        cout << ans << endl;
    }
    return 0;
}
