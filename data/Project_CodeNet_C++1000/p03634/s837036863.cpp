#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> tree(N);
    for ( int i = 0; i < N-1; i++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        tree.at(a).push_back(make_pair(b, c));
        tree.at(b).push_back(make_pair(a, c));
    }

    int Q, K;
    cin >> Q >> K;
    K--;
    vector<pair<int, int>> xy(Q);
    for ( int i = 0; i < Q; i++ ) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        xy.at(i) = make_pair(x, y);
    }

    vector<long long> dist(N, -1);  /* 頂点Kからの距離 */
    dist.at(K) = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(K);
    while ( !pq.empty() ) {
        int cur = pq.top(); pq.pop();
        for ( auto itr : tree.at(cur) ) {
            if ( dist.at(itr.first) < 0 ) {
                dist.at(itr.first) = itr.second + dist.at(cur);
                pq.push(itr.first);
            }
        }
    }

    for ( int i = 0; i < Q; i++ ) {
        int x = xy.at(i).first;
        int y = xy.at(i).second;
        printf("%lld\n", dist.at(x) + dist.at(y));
    }

    return 0;
}
