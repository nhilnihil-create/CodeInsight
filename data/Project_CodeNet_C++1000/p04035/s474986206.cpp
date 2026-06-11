#include <iostream>
#include <vector>
#include <tuple>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
const ll SIZE = 1e5 * 2 + 10, INF = 1e9;

vector<ll> vec;
ll sz[SIZE], hv[SIZE];

int main()
{
    fastInp;

    ll n, l;
    cin >> n >> l;
    vec.resize(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    ll good = -1;
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] + vec[i + 1] >= l) {
            good = i;
        }
    }

    if (good == -1) {
        cout << "Impossible";
        return 0;
    }

    cout << "Possible\n";
    vector<ll> ans;
    for (int i = 0; i < good; i++) {
        cout << i + 1 << "\n";
    }
    for (int i = n - 2; i > good; i--) {
        cout << i + 1 << "\n";
    }
    
    cout << good + 1;
    return 0;
}