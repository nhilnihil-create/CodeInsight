#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <climits>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for (int same = -100; same <= 100; same++)
    {
        int sum = 0;
        rep(i,n) {
            sum += (a[i]-same)*(a[i]-same);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}