#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int N;
vector<vector<int>> graph(100000), ko(100000);
vector<int> oya(100000, -1), deaph(100000);

void KI(int n) {
    for (int v : graph[n]) {
        if (v != oya[n]) {
            oya[v] = n;
            ko[n].push_back(v);
            deaph[v] = deaph[n] + 1;
            KI(v);
        }
    }
    return;
}

int SIZE(int n) {
    int ans = 1;
    for (int v : ko[n]) {
        ans += SIZE(v);
    }
    return ans;
}

int main() {
    cin >> N;
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    
    deaph[0] = 0;
    KI(0);
    int x = deaph[N - 1] - 1;
    int n = N - 1;
    rep(i, x / 2) n = oya[n];
    
    int SNUKE = SIZE(n);
    int FENNEC = N - SNUKE;
    if (FENNEC > SNUKE) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}
