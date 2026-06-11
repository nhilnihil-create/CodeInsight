#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    map<ll, ll> m;
    Rep (i, N) {
        ll a;
        cin >> a;
        m[a]++;
    }

    string ans = "No";

    if (m.size() == 2) {
        auto itr = m.begin();
        ll c = (*itr).first, a = (*itr).second;
        itr++;
        if ((*itr).first == c+1) {
            c++;
            ll b = (*itr).second;
            if (c-a > 0 && 2*(c-a) <= b) ans = "Yes";
        }

    } else if (m.size() == 1) {
        ll c = (*m.begin()).first;
        if (c == N-1 || 2*c <= N) ans = "Yes";
    }

    cout << ans << endl;
}