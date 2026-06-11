#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<double,int> DIP;
typedef pair<DIP,P> PP;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(2e5 + 5);
const double EPS = 1e-11;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

int main() {
    ll n, k, a[MAX_N], b[MAX_N], mask, ans = 0;
    cin >> n >> k;
    REP(i,n) cin >> a[i] >> b[i];
    REP(i,31){
        if(i>0){
            if(((k>>i)&1)==0)continue;
            else mask = ((k-(1LL<<i))|((1LL<<i)-1));
        }
        else mask = k;
        ll sum = 0;
        REP(j,n){
            if((a[j]|mask)<=mask)sum+=b[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
