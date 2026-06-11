#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    ll n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    if(n % 2 == 0){
        vector<ll> v;
        for(ll i = 0; i < n / 2; i++){
            v.emplace_back(a + c + 2 * c * i);
            v.emplace_back(a - c - 2 * c * i);
        }
        sort(ALL(v));
        for(ll i = 0; i < v.size(); i++){
            ll l = v[i] - (d - c) * (n - 1 - i);
            if(l <= b && b <= l + (d - c) * (n - 1)){
                cout << "YES" << endl;
                return 0;
            }
        }
    }else{
        vector<ll> v;
        v.emplace_back(a);
        for(ll i = 1; i <= n / 2; i++){
            v.emplace_back(a + 2 * c * i);
            v.emplace_back(a - 2 * c * i);
        }
        sort(ALL(v));
        for(ll i = 0; i < v.size(); i++){
            ll l = v[i] - (d - c) * (n - 1 - i);
            if(l <= b && b <= l + (d - c) * (n - 1)){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}