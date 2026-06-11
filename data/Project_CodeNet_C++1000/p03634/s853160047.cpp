#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, a, b, c, q, k, x, y;
    vector<vector<pair<long long,long long>>> children;
    vector<long long> dists;
    vector<bool> visited;
    queue<pair<long long,long long>> moves;
    pair<long long,long long> curr;
    
    cin >> n;
    
    for (long i=0; i<=n; i++) {
        children.push_back({});
        dists.push_back(0);
        visited.push_back(false);
    }
    
    for (long i=0; i<n-1; i++) {
        cin >> a >> b >> c;
        children[a].push_back(make_pair(b,c));
        children[b].push_back(make_pair(a,c));
    }
    
    cin >> q >> k;
    
    visited[k] = true;
    moves.push(make_pair(k,0));
    
    while (moves.size()>0) {
        curr = moves.front();
        moves.pop();
        
        for (auto i : children[curr.first]) {
            if (!visited[i.first]) {
                moves.push(make_pair(i.first, curr.second+i.second));
                dists[i.first] = curr.second+i.second;
                visited[i.first] = true;
            }
        }
    }
    
    for (long i=0; i<q; i++) {
        cin >> x >> y;
        cout << dists[x]+dists[y] << endl;
    }
    
    return 0;
}