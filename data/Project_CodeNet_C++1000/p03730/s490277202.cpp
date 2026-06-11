#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    int A,B,C;
    cin >> A >> B >> C;
    vector<int> V(100);
    rep(i,100) {
        V[i] = A*(i + 1)%B;
    }
    int flag = 0;
    rep(j,100) {
        if (V[j] == C) {
            cout << "YES" << endl;
            flag++;
            break;
        }
    }
    if (flag == 0) {
        cout << "NO" << endl;
    }
}

