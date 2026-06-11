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
    vec p(N), order(N);
    Rep (i, N) {
        cin >> p[i];
        p[i]--;
        order[p[i]] = i;
    }

    vec a(N, 1), b(N, 1);
    ll x = 25000;
    Rep (i, N) {
        a[i] += x*i;
        b[N-1-i] += x*i;
        a[i] += order[i];
    }

    Rep (i, N) {
        cout << a[i] << " \n"[i==N-1];
    }
    Rep (i, N) {
        cout << b[i] << " \n"[i==N-1];
    }
    return 0;


}