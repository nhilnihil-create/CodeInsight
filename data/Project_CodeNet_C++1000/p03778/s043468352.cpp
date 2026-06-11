#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    int W,a,b;
    cin >> W >> a >> b;
    if (a <= b) {
        cout << max(0,b - a - W) << endl;
    }
    else {
        cout << max(0,a - b - W) << endl;
    }
}

