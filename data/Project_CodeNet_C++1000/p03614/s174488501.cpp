#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    int p[n];
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }

    int ans = 0;
    rep(i, n-1) {
        if(p[i] == i) {
            swap(p[i], p[i+1]);
            ans++;
        }
    }
    if(p[n-1] == n-1) {
        ans++;
    }

    cout << ans << endl;
    return 0;
}