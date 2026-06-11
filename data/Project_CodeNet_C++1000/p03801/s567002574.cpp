#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e5 + 10, S2 = 1e7 * 2;

vector<pair<ll, ll>> vec;
vector<ll> cnt, pref;
vector<ll> add[SIZE];

int main() {
    fastInp;

    ll n;
    cin >> n;

    cnt.resize(n);
    pref.resize(n);

    ll curMx = -1, ind = -1;
    vector<ll> k(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        k[i] = a;
        if (curMx < a) {
            vec.push_back({ a, i });
        }
        else {
            
        }
        if (curMx < a) {
            ind = i;
        }
        curMx = max(curMx, a);
    }

    sort(vec.rbegin(), vec.rend());

    curMx = -1, ind = -1;
    for (int i = 0; i < n; i++) {
        ll a;
        a = k[i];
        if (curMx < a) {
        }
        else {
            int l = -1, r = vec.size();
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (vec[mid].first >= a) {
                    l = mid;
                }
                else {
                    r = mid;
                }
            }
            add[l].push_back(a);
        }
        if (curMx < a) {
            ind = i;
        }
        curMx = max(curMx, a);
    }

    ll curAdd = 0; vec.push_back({ 0, 0 });
    for (int i = 0; i < vec.size() - 1; i++) {
        ll s = 0;
        for (auto cur : add[i]) {
            s += abs(vec[i + 1].first - cur);
        }
        cnt[vec[i].second] += (i + 1 + curAdd) * abs(vec[i].first - vec[i + 1].first) + s;
        curAdd += add[i].size();
    }

    for (int i = 0; i < n; i++) {
        cout << cnt[i] << "\n";
    }
    return 0;
}

