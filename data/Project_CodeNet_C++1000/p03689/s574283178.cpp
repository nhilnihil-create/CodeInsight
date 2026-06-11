#include <iostream>
#include <vector>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <random>
#include <map>
#include <string>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 3e5 + 10, INF = 1e9 - 1, K = 400;


int main()
{
    fastInp;

    ll n, m, h, w;
    cin >> n >> m >> h >> w;
    ll s = (h * w);
    if (h * w == 1) {
        cout << "No";
        return 0;
    }
    ll vl = INF / (h * w - 1);
    ll c = vl * (h * w - 1) + 1;

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i % h == (h - 1) && j % w == (w - 1)) {
                cnt -= c;
            }
            else {
                cnt += vl;
            }
        }
    }

    if (cnt <= 0) {
        cout << "No";
    }
    else {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i % h == (h - 1) && j % w == (w - 1)) {
                    cout << -c << " ";
                }
                else {
                    cout << vl << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}