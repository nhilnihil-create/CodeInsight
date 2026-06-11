#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int x, A, B;
    cin >> x >> A >> B;
    if (B-A <= 0){
        cout << "delicious" << endl;
    }
    else if (B-A <= x)cout << "safe" << endl;
    else cout << "dangerous" << endl;
}