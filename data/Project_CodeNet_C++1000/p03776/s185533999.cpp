#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int Nmax = 60;

vector<vector<ll>> C(Nmax, vector<ll>(Nmax));

void PascalTriangle() {

    rep(i, Nmax) {
        C[i][0] = C[i][i] = 1;
    }
    
    for(int i = 2; i < Nmax; i++) {
        for(int j = 1; j < i; j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> v(n);
    rep(i, n) {
        cin >> v[i];
    } 
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll sum = 0;
    rep(i, a) {
        sum += v[i];
    }
    double avg = (double)sum/a;
    printf("%.7f\n", avg);

    PascalTriangle();

    ll ans = 0;
    if(v[0] != v[a-1]) {

        int x = 0, y = 0;
        rep(i, n) {
            if(v[i] == v[a-1]) {
                x++;
            }
        }
        rep(i, a) {
            if(v[i] == v[a-1]) {
                y++;
            }
        }

        ans = C[x][y];
    }
    else if(v[0] == v[a-1]) {

        int x = 0;
        rep(i, n) {
            if(v[i] == v[0]) {
                x++;
            }
        }

        for(int i = a; i <= min(b, x); i++) {
            ans += C[x][i];
        }
    }

    cout << ans << endl;
    return 0;
}