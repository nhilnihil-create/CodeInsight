#include <numeric>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(ll i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vc = vector<char>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vb = vector<bool>;
using vvb = vector<vb>;
const ll MOD = 1e9 + 7;
set<char> alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    tuple<double, int, int> ans(0, 100 * A, 0);

    for (int i = 0; 100 * A * i <= F; i++) {
        for (int j = 0; 100 * A * i + 100 * B * j <= F; j++) {
            for (int k = 0; 100 * A * i + 100 * B * j + C * k <= F; k++) {
                for (int l = 0; 100 * A * i + 100 * B * j + C * k + D * l <= F; l++) {
                    int water = 100 * A * i + 100 * B * j;
                    int sugar = C * k + D * l;
                    int all = water + sugar;
                    if (100 * sugar <= E * water && all > 0) {
                        double max = get<0>(ans);
                        double d = sugar*100.0 / all;
                        if (max < d) {
                            ans = make_tuple(d, all, sugar);
                        }
                    }
                }
            }
        }
    }
    cout<< get<1>(ans) << " " << get<2>(ans) << endl;
}