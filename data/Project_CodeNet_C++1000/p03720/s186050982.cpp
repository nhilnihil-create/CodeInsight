#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const ll oo = 1e18;
const ll mod = 998244353,maxn = 3030;
const double PI = acos(-1);


int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, b;

    cin >> n >> m;

    vector<int> ans(n, 0);

    for (int i=0; i<m; i++){
        cin >> a >> b;
        ans[--a]++;
        ans[--b]++;
    }

    for (auto x : ans) cout << x << endl;
    return 0;
}