#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1001001001
#define LINF (1LL << 62)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solv() {
    string s;
    cin >> s;
    int n = s.size();
    int g = 0, p = 0, point = 0;
    rep(i, n) {
        if (p < g) {
            if (s[i] == 'g') {
                p++;
                point++;
            } else {
                p++;
            }
        } 
        else {
            if (s[i] == 'g') {
                g++;
            } else {
                g++;
                point--;
            }
        }
    }
    cout << point << endl;
}

int main() {
    solv();
    return 0;
}