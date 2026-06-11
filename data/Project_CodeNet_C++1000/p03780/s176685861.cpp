#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
    }

    vector<vector<bool>> ok1(n, vector<bool>(k, false));
    {
        ok1.at(0).at(0) = true;
        for(int i = 0; i < n - 1; ++i){
            copy(ok1.at(i).begin(), ok1.at(i).end(), ok1.at(i + 1).begin());
            for(int j = 0; j < k; ++j){
                if(ok1.at(i).at(j) && j + a.at(i) < k){
                    ok1.at(i + 1).at(j + a.at(i)) = true;
                }
            }
        }
    }

    vector<vector<bool>> ok2(n, vector<bool>(k, false));
    {
        ok2.at(n - 1).at(0) = true;
        for(int i = n - 1; i > 0; --i){
            copy(ok2.at(i).begin(), ok2.at(i).end(), ok2.at(i - 1).begin());
            for(int j = 0; j < k; ++j){
                if(ok2.at(i).at(j) && j + a.at(i) < k){
                    ok2.at(i - 1).at(j + a.at(i)) = true;
                }
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i){
        vector<ll> v1, v2;
        for(int j = 0; j < k; ++j){
            if(ok1.at(i).at(j)){ v1.push_back(j); }
            if(ok2.at(i).at(j)){ v2.push_back(j); }
        }
        ll tmp = 0;
        ll i1 = 0, i2 = v2.size() - 1;
        while(i1 < v1.size() && i2 >= 0){
            if(v1.at(i1) + v2.at(i2) < k){
                tmp = max(tmp, v1.at(i1) + v2.at(i2));
                i1++;
            }else{
                i2--;
            }
        }
        if(tmp + a.at(i) < k){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
