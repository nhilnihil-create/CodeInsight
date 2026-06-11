#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, int> P3;
const ll MOD = ll(1e9)+7;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(1e5 + 5);
const double EPS = 1e-10;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

int main() {
    ll n, m, a[MAX_N], sum=0;
    string ans = "YES";
    cin >> n;
    REP(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum%(n*(n+1)/2)>0) ans = "NO";
    else{
        m = sum/(n*(n+1)/2);
        ll cnt = 0;
        a[n] = a[0];
        REP(i,n){
            ll dif = a[i+1] - a[i]; // 前後の差を見るとm,m,,...,m-n,m,...になっている
            if(abs(dif-m)%n!=0){
                ans = "NO";
                break;
            }
            else{
                cnt += abs(dif-m)/n;
            }
        }
        if(cnt!=m) ans = "NO";
    }
    cout << ans << endl;
    return 0;
}
