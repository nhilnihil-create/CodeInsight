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

int main()
{
    fastInp;

    ll a, b;
    cin >> a >> b;
    if (a <= 0 && b >= 0) {
        cout << "Zero";
        return 0;
    }

    if (a < 0) {
        if ((min(-1ll, b) - a) % 2 == 0) {
            cout << "Negative";
            return 0;
        }
    }
    
    cout << "Positive";
    return 0;
}