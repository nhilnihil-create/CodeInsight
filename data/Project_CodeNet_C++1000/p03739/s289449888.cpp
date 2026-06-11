#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cassert>
#include <unordered_map>

#define _(x) { cout << #x << " = " << x << " "; }

const double E = 1e-8;
const double PI = acos(-1);
typedef long long ll;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    ll sum = 0, ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        if (i % 2 == 0) {
            if (sum <= 0) {
                ans1 += (1 - sum);
                sum = 1;
            }
        } else if (sum >= 0) {
            ans1 += (sum+1);
            sum = -1;
        }
    }
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        if (i % 2 == 1) {
            if (sum <= 0) {
                ans2 += (1-sum);
                sum = 1;
            } 
        } else if (sum >= 0) {
            ans2 += (1+sum);
            sum = -1;
        }
    }
    cout << min(ans1, ans2) << '\n';
    return 0;
}

