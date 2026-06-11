#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

vector<int> eds[120000];
int was[120000];
int n;

int dfs1(int v) {
    was[v] = 1;
    int ans = 0;
    for (int u: eds[v]) {
        if (!was[u]) {
            int x = dfs1(u);
            x += 1;
            ans ^= x;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        eds[a].push_back(b);
        eds[b].push_back(a);
    }
    int x = dfs1(0);
    if (x)
        cout << "Alice\n";
    else
        cout << "Bob\n";
    return 0;
}


