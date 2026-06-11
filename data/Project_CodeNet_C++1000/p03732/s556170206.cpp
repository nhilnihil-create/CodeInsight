#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    ll n, w;
    cin >> n >> w;
    vector<ll> weight, value;
    weight.resize(n);
    value.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> weight.at(i);
        cin >> value.at(i);
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(301, 0));
    for(int i = 0; i < n; ++i){
        for(int j = n - 1; j >= 0; --j){
            for(int l = 0; l + (weight.at(i) - weight.at(0)) <= 300; ++l){
                dp.at(j + 1).at(l + weight.at(i) - weight.at(0)) = max(
                    dp.at(j + 1).at(l + weight.at(i) - weight.at(0)),
                    dp.at(j).at(l) + value.at(i)
                );
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= 300; ++j){
            if(w >= i * weight.at(0) + j){
                // cerr << i << ' ' << j << ' ' << dp.at(i).at(j) << endl;
                ans = max(ans, dp.at(i).at(j));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
