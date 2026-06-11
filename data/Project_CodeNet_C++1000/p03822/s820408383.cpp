#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mnx = 1e6 + 9;
const int mod = 1e9 + 7;

ll n, x;
vector<int> g[mnx];

ll dfs(int v){
    vector<int> q;
    for(auto to : g[v]){
        q.push_back(dfs(to));
    }
    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());
    int ans = g[v].size();
    for(int i = 0; i < q.size(); i++){
        ans = max(ans * 1LL, 1LL * (q[i] + i + 1));
    }
    return ans;
}

int main() {

cin >> n;

for(int i = 2; i <= n; i++){
    cin >> x;
    g[x].push_back(i);
}

cout << dfs(1) << '\n';

return 0;

}
