#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)

int main(){
    ll n, k;
    cin >> n >> k;

    int max_bit = 31;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    vector<ll> candidates;
    candidates.push_back(k);
    for(int i = 1; i < max_bit; i++){
        if(k&(1<<i)){
            ll tmp = k;
            tmp -= 1<<i;
            tmp |= (1<<i)-1;
            candidates.push_back(tmp);
        }
    }
/*
    for(int i = 0; i < candidates.size(); i++){
        cout << bitset<12>(candidates[i]) << endl;
    }
*/
    ll ans = -1;
    for(int i = 0; i < candidates.size(); i++){
        ll tmpsum = 0;
        for(int j = 0; j < n; j++){
            bool isOK = true;
            for(int bit = 0; bit < max_bit; bit++){
                if(!(candidates[i]&(1<<bit)) && a[j]&(1<<bit)){
                    isOK = false;
                    break;
                }
            }
            if(isOK){
                tmpsum += b[j];
            }
        }
        ans = max(ans,tmpsum);
    }
    cout << ans << endl;

}
