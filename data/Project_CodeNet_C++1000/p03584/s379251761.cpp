#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX 30

signed main(){
    int n;
    ll k;
    cin >> n >> k;
    ll a[n],b[n];
    REP(i,n){
        cin >> a[i] >> b[i];
    }
    vector<ll> cand;
    for(int bit = MAX - 1; bit >= 0; bit--){
        if(k & 1 << bit){
            ll t = 0;
            for(int i = MAX - 1; i > bit; i--){
                if(k & 1LL << i) t |= 1LL << i;
            }
            for(int i = bit - 1; i >= 0; i--){
                t |= 1LL << i;
            }
            cand.emplace_back(t);
        }
    }
    cand.emplace_back(k);
    ll ans = 0;
    for(auto c : cand){
        ll sum = 0;
        for(int i = 0; i < n; i++){
            for(int bit = 0; bit < MAX; bit++){
                if(a[i] & 1LL << bit && !(c & 1LL << bit)) goto no;
            }
            sum += b[i];
            no:;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}