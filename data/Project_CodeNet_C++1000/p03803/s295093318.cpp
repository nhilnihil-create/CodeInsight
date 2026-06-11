#include <bits/stdc++.h>
#include <numeric>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;	

int main() {
    int a, b; cin >> a >> b;
    if (a == b) {
        cout << "Draw" << endl;
    }
    else if (a == 1) {
        cout << "Alice" << endl;
    }
    else if (b == 1) {
        cout << "Bob" << endl;
    }
    else if (a > b) {
        cout << "Alice" << endl;
    }
    else {
        cout << "Bob" << endl;
    }
}
