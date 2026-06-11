#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

vi es[100005];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n,m;
    cin >> n >> m;

    rep(i, m) {
        int a, b;
        cin>> a >> b;
        a--; b--;
        es[a].push_back(b);
        es[b].push_back(a);
    }

    deque<int> deq;
    deq.push_back(0);
    set<int> s;
    s.insert(0);

    while(true) {
        int u = deq.front();
        bool ok = true;
        for(auto v: es[u]) {
            if (s.find(v) == s.end()) {
                deq.push_front(v);
                ok = false;
                s.insert(v);
                break;
            }
        }

        if (ok) break;
    }

    while(true) {
        int u = deq.back();
        bool ok = true;
        for(auto v: es[u]) {
            if (s.find(v) == s.end()) {
                deq.push_back(v);
                s.insert(v);
                ok = false;
                break;
            }
        }

        if (ok) break;
    }

    cout << deq.size() << endl;
    for(auto u : deq) {
        cout << u + 1;
        if (u != deq.back()) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
