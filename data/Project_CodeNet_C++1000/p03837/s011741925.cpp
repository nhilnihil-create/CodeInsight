#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, a, b;
    ll c;
    cin >> n >> m;
    vector<bool> vrow(n+1,0);
    vector<vector<bool>> visited(n+1,vrow);
    vector<vector<pair<int,ll>>> paths(n+1);
    for (int i=0; i<m; i++) {
        cin >> a >> b >> c;
        paths[a].push_back(make_pair(b,c));
        paths[b].push_back(make_pair(a,c));
    }
    priority_queue<pair<ll,int>> moves;
    for (int i=1; i<=n; i++) {
        vector<ll> dists(n+1,1000000000);
        vector<vector<ll>> links(n+1);
        dists[i] = 0;
        moves.push(make_pair(0,i));
        while (moves.size()>0) {
            pair<ll,int> curr = moves.top();
            moves.pop();
            for (auto j : paths[curr.second]) {
                if (-curr.first+j.second > dists[j.first]) continue;
                if (-curr.first+j.second == dists[j.first]) {
                    links[j.first].push_back(curr.second);
                    continue;
                }
                links[j.first].clear();
                links[j.first].push_back(curr.second);
                dists[j.first] = -curr.first+j.second;
                moves.push(make_pair(curr.first-j.second,j.first));
            }
        }
        for (int j=1; j<=n; j++) for (auto k : links[j]) {
            visited[k][j] = true;
            visited[j][k] = true;
        }
    }
    ll res = m*2;
    for (auto i : visited) for (auto j : i) if (j) res--;
    cout << res/2;
    return 0;
}