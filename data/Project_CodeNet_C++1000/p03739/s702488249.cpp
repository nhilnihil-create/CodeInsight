#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;





int main() {
    int n; cin >> n;
    vector<ll> A(n);
    rp(i, 0, n) scanf("%lld", &A.at(i));
    ll res1 = 0ll;
    ll res2 = 0ll;
    vector<ll> sum1(n);
    vector<ll> sum2(n);
    if(A.at(0) == 0) {
        sum1.at(0) = 1ll;
        sum2.at(0) = -1ll;
        res1 ++; res2++;
    }
    else if(A.at(0) > 0) {
        sum1.at(0) = A.at(0);
        sum2.at(0) = -1ll;
        res2 += A.at(0) + 1ll;
    }
    else {
        sum1.at(0) = A.at(0);
        sum2.at(0) = 1ll;
        res2 += -A.at(0) + 1ll;
    }

    rp(i, 1, n) {
        sum1.at(i) = sum1.at(i-1) + A.at(i);
        if(sum1.at(i) == 0) {
            if(sum1.at(i-1) < 0) sum1.at(i) = 1ll;
            else sum1.at(i) = -1ll;
            res1 ++;
        }
        if(sum1.at(i) * sum1.at(i-1) > 0) {
            if(sum1.at(i) < 0) {
                res1 += -sum1.at(i) + 1ll;
                sum1.at(i) = 1ll;
                
            }
            else {
                res1 += sum1.at(i) + 1ll;
                sum1.at(i) = -1ll;
            }
        }

        sum2.at(i) = sum2.at(i-1) + A.at(i);
        if(sum2.at(i) == 0) {
            if(sum2.at(i-1) < 0) sum2.at(i) = 1ll;
            else sum2.at(i) = -1ll;
            res2 ++;
        }
        if(sum2.at(i) * sum2.at(i-1) > 0) {
            if(sum2.at(i) < 0) {
                res2 += -sum2.at(i) + 1ll;
                sum2.at(i) = 1ll;
            }
            else {
                res2 += sum2.at(i) + 1ll;
                sum2.at(i) = -1ll;
            }
        }
    }
    ll res = min(res1, res2);
    cout << res << endl;
    return 0;
}