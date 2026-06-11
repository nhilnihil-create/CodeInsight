#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(it) it.begin(), it.end()
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORU(i, a, b, s) for(int i = a; i < b; i += s)
#define FORD(i, a, b, s) for(int i = a; i > b; i -= s)
#define endl "\n"
ll INF = 2e18;
ll MOD = 1e9 + 7;

int i, j, k, t;

int main() {
    int N;
    cin >> N;

    unordered_set<int> m;
    FOR(i, N) {
        cin >> t;
        if(m.find(t) == m.end()) {
            m.insert(t);
        } else {
            m.erase(t);
        }
    }
    cout << distance(all(m)) << endl;
}