#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

double A, B, C, D, E, F;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
    cin >> A >> B >> C >> D >> E >> F;

    double water_total = 0;  
    double sugar_total = 0;  
    double percent = 0;
    int max_v = F;

    for (int a = 0; a <= max_v; a += A * 100) {
        for (int b = 0; b <= max_v; b += B * 100) {
            for (int c = 0; c <= max_v; c += C) {
                for (int d = 0; d <= max_v; d += D) {
                    ll water = a + b;
                    ll sugar = c + d;
                    if (water + sugar > F) continue;

                    double tmp = (double)sugar / (sugar + water);
                    double max_rate = (double)E / (100 + E);
                    if (max_rate < tmp) continue;

                    // cout << sugar << " " << (sugar + water) << endl;
                    // if (percent < tmp) {
                    if (percent <= tmp) {
                        water_total = water;
                        sugar_total = sugar;
                        percent = tmp; 
                    }
                }
            }
        }
    } 

    cout << water_total + sugar_total << " " << sugar_total << endl;
}