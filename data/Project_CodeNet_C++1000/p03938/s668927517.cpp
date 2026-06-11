#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int p[n], a[n], b[n];
    rep(i, n) {
        cin >> p[i];
        p[i]--;
        a[i] = (i+1)*n;
        b[i] = (n-i)*n;
    }

    rep(i, n) {
        a[p[i]] += i;
    }

    rep(i, n-1) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << "\n";

    rep(i, n-1) {
        cout << b[i] << " ";
    }
    cout << b[n-1];

    cout << endl;
    return 0;
}