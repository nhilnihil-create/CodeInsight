#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MAXN 1000010
#define rep(i, n) for(int i = 0; i < (n); ++i)
const ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

bool pairCompare(const P &firstElof, const P &secondElof) {
    return firstElof.second < secondElof.second;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int m = max(a, max(b, c));
    bool flag = false;
    if(m == a) {
        if(a == b + c) {
            flag = true;
        }
    } else if(m == b) {
        if(b == a + c) {
            flag = true;
        }
    } else {
        if(c == a + b) {
            flag = true;
        }
    }

    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
