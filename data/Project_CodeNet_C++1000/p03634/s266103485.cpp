#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

struct Node {
    bool fixed = false;
    bool onKP = false;
    bool Kon  = false;
    int cost = 0;
    int depth = 0;
    int parent = 0;
    ll  root_cost = 0;
};

int K, root;
vector<int> KP;

void makeKP(vector<Node>& NO) {
    int p = K;
    stack<int> ST;
    do {
        ST.push(p);
        p = NO.at(p).parent;
    } while (p != 0);
 
    ll cost = 0;
    int depth = 0;
    while(!ST.empty()) {
        auto pos = ST.top(); ST.pop();
        KP.emplace_back(pos);
        NO[pos].depth = depth++;
        cost += NO[pos].cost;
        NO[pos].root_cost = cost;
        NO[pos].onKP = true;
        NO[pos].fixed = true;
    }
    root = KP[0];
}


ll path(vector<Node>& NO, int x) {
    if (NO[x].fixed) {
        if (NO[x].onKP) {
            return NO[K].root_cost - NO[x].root_cost;
        } else if (NO[x].Kon) {
            return NO[x].root_cost - NO[K].root_cost;
        } else {
            int p = x;
            while (p != root && !NO[p].onKP) p = NO[p].parent;
            if (p == root) {
                return NO[x].root_cost + NO[K].root_cost;
            } else {
                return NO[x].root_cost + NO[K].root_cost - 2 * NO[p].root_cost;
            }
        }
    }

    int p = x;
    int connected = 0;
    stack<int> ST;
    bool KON = false;
    do {
        ST.push(p);
        if (connected == 0 && NO[p].onKP) connected = p;
        p = NO.at(p).parent;
        if (p == K) KON = true;
    } while (p != root);
 
    ll cost = 0;
    int depth = 1;
    while(!ST.empty()) {
        auto pos = ST.top(); ST.pop();
        if (KON && depth > NO[K].depth) NO[pos].Kon = true;
        NO[pos].depth = depth++;
        cost += NO[pos].cost;
        NO[pos].root_cost = cost;
        NO[pos].fixed = true;
    }
    if (connected != 0) {
        return NO[x].root_cost + NO[K].root_cost - 2 * NO[connected].root_cost;
    } else {
        return NO[x].root_cost + NO[K].root_cost;
    }
}

int main() {
    int N; cin >> N;
    vector<Node> NO(N+1);
    rep(i, N-1) {
        int a, b, c; cin >> a >> b >> c;
        NO.at(b).parent = a;
        NO.at(b).cost = c;
    }
    int Q; cin >> Q >> K;
    makeKP(NO);
    int KD = NO[K].depth;

    rep(i,Q) {
        int x, y; cin >> x >> y;
        ll cost = 0;
        int XD;

        if (K != x) cost = path(NO, x);

        if (K == y) {
            cout << cost << endl;
            continue;
        }

        cost += path(NO, y);
        cout << cost << endl;
    }
}
