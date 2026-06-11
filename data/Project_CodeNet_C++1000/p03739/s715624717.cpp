#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>

using namespace std;

#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
const int MOD = 1e9 + 7;





int main() {
    int n;
    cin >> n;
    vll a(n + 1);
    rep(i, n) cin >> a[i];
    ll even = 0;
    ll odd = 0;

    vll sum(n + 1);
    sum[0] = a[0];
    rep(i, n) {
        if (i % 2 == 0 && sum[i] <= 0) {
                even += 1 - sum[i];
                sum[i] = 1;
        }
        else if (i % 2 == 1 && sum[i] >= 0) {
                even += 1 + sum[i];
                sum[i] = -1;
        }
        sum[i + 1] = sum[i] + a[i + 1];
    }

    vll summ(n + 1);
    summ[0] = a[0];
    rep(i, n) {
        if (i % 2 == 0 && summ[i] >= 0) {
                odd += 1 + summ[i];
                summ[i] = -1;
            }
        else if (i % 2 == 1 && summ[i] <= 0) {
                odd += 1 - summ[i];
                summ[i] = 1;
        }
        summ[i + 1] = summ[i] + a[i + 1];
    }
    ll ans = min(odd, even);
    cout << ans << endl;
}