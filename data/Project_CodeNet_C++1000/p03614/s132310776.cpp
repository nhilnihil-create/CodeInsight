#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10;



int main()
{
    fastInp;

    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (auto &c : vec) cin >> c;

    ll pr = 0;

    vec.push_back(vec.size() + 10);

    ll ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        vec[i]--;
        if (pr == 1 && vec[i] == i) {
            ans++;
            pr = 0;
        } else if (pr == 1 && vec[i] != i) {
            ans++;
            pr = 0;
        } else if (pr == 0 && vec[i] == i) {
            pr = 1;
        }
    }

    cout << ans;

    return 0;
}