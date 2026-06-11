#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    int four = 0, two = 0, one = 0;
    REP(i, 0, N) {
        int a; cin >> a;
        if (a % 4 == 0) {
            four++;
        } else if (a % 2 == 0) {
            two++;
        } else {
            one++;
        }
    }
    
    if (two == 0) {
        if (one > four + 1) {
            cout << "No" << endl;
            return 0;
        }
    } else {
        if (one > four) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}