#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INF 1e9
#define MAX_N 100001

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int N;
vector<int> G[MAX_N];

int prv[MAX_N];

void bfs() {
    fill(prv, prv + N, -1);
    queue<int> que;
    prv[N - 1] = -2;
    que.push(N - 1);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            int nxt = G[v][i];
            if (prv[nxt] == -1) {
                prv[nxt] = v;
                que.push(nxt);
            }
        }
    }
}

int get_score(int s, int t) {
    int res = 0;
    bool used[MAX_N];
    fill(used, used + N, false);
    queue<int> que;
    
    used[s] = true;
    res++;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            int nxt = G[v][i];
            if (!used[nxt] && nxt != t) {
                used[nxt] = true;
                res++;
                que.push(nxt);
            }
        }
    }
    
    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    
    bfs();
    vector<int> path;
    int n = 0;
    while (n != N - 1) {
        path.push_back(n);
        n = prv[n];
    }
    path.push_back(N - 1);
    
    int b, w, len = (int)path.size();
    if (len % 2 == 0) {
        b = len / 2 - 1;
    } else {
        b = (len + 1) / 2 - 1;
    }
    w = b + 1;
    
    int b_score = get_score(path[b], path[w]);
    int w_score = get_score(path[w], path[b]);
    
    if (b_score <= w_score) {
        cout << "Snuke" << endl;
    } else {
        cout << "Fennec" << endl;
    }
    
    return 0;
}
