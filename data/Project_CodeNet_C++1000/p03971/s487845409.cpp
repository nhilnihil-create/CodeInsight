#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
ll factorial(int i) {       //階乗
    if (i == 0) return 1;
    return (factorial(i - 1)) * i;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int b_count = 0;
    int join = 0;
    rep(i, s.size()) {
        if(s[i] == 'c') {
            cout << "No" << "\n";
        }
        else if(s[i] == 'a' && join < a + b) {
            cout << "Yes" << "\n";
            join++;
        }
        else if(s[i] == 'b' && join < a + b && b_count < b) {
            cout << "Yes" << "\n";
            b_count++;
            join++;
        }
        else cout << "No" << "\n";
    }
    return 0;
}