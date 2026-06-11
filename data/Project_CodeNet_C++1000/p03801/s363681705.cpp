#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<pair<ll, int> > p(n);
    rep(i, n) p[i] = make_pair(a[i], i);

    sort(p.begin(), p.end());

    vector<ll> ans(n, 0);

    int i = n-1;
    while (i >= 0) {
        int j = i-1;
        while (p[j].second > p[i].second && j >= 0) {
            j--;
        }
        if (j < 0) {
            for (int k = j+1; k < i; k++) {
                ans[p[i].second] += p[k].first;
            }
            ans[p[i].second] += p[i].first * (n-i);
        } else {
            for (int k = j+1; k < i; k++) {
                ans[p[i].second] += p[k].first - p[j].first;
            }
            ans[p[i].second] += (p[i].first - p[j].first) * (n-i);
        }
        i = j;
    }

    rep(i, n) cout << ans[i] << endl;
    

    return 0;

}
