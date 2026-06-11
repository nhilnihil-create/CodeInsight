#include "bits/stdc++.h"

using namespace std;

//// my original verion
//void Main() {
//    long long N;
//    cin >> N;
//    map<long long, set<pair<long long, long long> > > tree;
//    for (long long i = 0; i < N - 1; ++i) {
//        long long a, b, c;
//        cin >> a >> b >> c;
//        if (tree.count(a) == 0) {
//            tree.insert(make_pair(a, set<pair<long long, long long> >()));
//        }
//        tree[a].insert(make_pair(b, c));
//        if (tree.count(b) == 0) {
//            tree.insert(make_pair(b, set<pair<long long, long long> >()));
//        }
//        tree[b].insert(make_pair(a, c));
//    }
//
//    long long Q, K;
//    cin >> Q >> K;
//    vector<long long> distanceFromK(N + 1, -1LL);
//    distanceFromK[K] = 0LL;
//    queue<long long> q;
//    q.push(K);
//    while (!q.empty()) {
//        long long f = q.front();
//        q.pop();
//        long long distanceFromTop = distanceFromK[f];
//        const set<pair<long long, long long> >& nextNodes = tree[f];
//        for (auto e : nextNodes) {
//            if (distanceFromK[e.first] < 0) {
//                q.push(e.first);
//                distanceFromK[e.first] = e.second + distanceFromTop;
//            }
//        }
//    }
//
//    for (long long i = 0; i < Q; ++i) {
//        long long x, y;
//        cin >> x >> y;
//        long long dx = distanceFromK[x];
//        long long dy = distanceFromK[y];
//        cout << (dx + dy) << endl;
//    }
//
//}

void dfs(int curr, const map<int, set<pair<int, long long> > >& tree, vector<long long>& distance) {
    auto nextNodes = tree.at(curr);
    for (auto p : nextNodes) {
        int next = p.first;
        long long d = p.second;
        if (distance[next] < 0) {
            distance[next] = distance[curr] + d;
            dfs(next, tree, distance);
        }
    }
}

void Main() {
    int N;
    cin >> N;
    map<int, set<pair<int, long long> > > tree;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        tree[a].insert(make_pair(b, c));
        tree[b].insert(make_pair(a, c));
    }
    int Q, K;
    cin >> Q >> K;
    vector<long long> distance(N + 1, -1LL);
    distance[K] = 0LL;
    dfs(K, tree, distance);

    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        cout << (distance[x] + distance[y]) << endl;
    }

}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
