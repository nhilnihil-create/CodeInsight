#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    string a, b, c;
    char turn = 'a';
    cin >> a >> b >> c;
    while (1) {
        if (turn == 'a') {
            if (a.empty()) {
                cout << "A" << endl;
                break;
            }
            turn = a.front();
            a = a.substr(1, a.size() - 1);
        }
        else if (turn == 'b') {
            if (b.empty()) {
                cout << "B" << endl;
                break;
            }
            turn = b.front();
            b = b.substr(1, b.size() - 1);
        }
        else {
            if (c.empty()) {
                cout << "C" << endl;
                break;
            }
            turn = c.front();
            c = c.substr(1, c.size() - 1);
        }
    }
    return 0;
}