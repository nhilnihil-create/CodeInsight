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
#include <random>
#include <cstring>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll MAX = 55;
mat Com(MAX, vec(MAX));

void com() {
    Rep (i, MAX) {
        Rep (j, MAX) {
            Com[i][j] = 0;
        }
    }
    Com[0][0] = 1;
    for (ll i = 1; i < MAX; i++) {
        Com[i][0] = 1;
        for (ll j = 1; j < MAX; j++) {
            Com[i][j] = Com[i-1][j-1] + Com[i-1][j];
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << fixed << setprecision(10);

    ll N, A, B;
    cin >> N >> A >> B;
    vec v(N);
    Rep (i, N) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    double ans = 0;
    for (ll i = N-1; i >= N-A; i--) {
        ans += v[i];
    }

    ans /= A;
    com();

    ll cnt = 0;
    ll choose = 0;
    Rep (i, N) {
        if (v[i] == v[N-A]) {
            cnt++;
            if (i >= N-A) {
                choose++;
            }
        }
    }

    ll check = Com[cnt][choose];
    if (v[N-1] == v[N-A]) {
        for (ll i = 1; i <= B-A; i++) {
            check += Com[cnt][choose+i];
        }
    }

    cout << ans << "\n" << check << "\n";
}