#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;






int main() {
    int n,x; cin >> n >> x;
    vector<int> vec;
    for(int i = 0;i < n;i++){
        int y; cin >> y; vec.push_back(y);
    }
    ll ans = 0;
    for(int i = 1;i < n;i++){
        if(vec[i-1]+vec[i] > x){
                int total = (vec[i] + vec[i-1])-x;
                ans += total;
            if(vec[i] > total){
                vec[i] -= total;
            }else{
                total -= vec[i];
                vec[i] = 0;
                vec[i-1] -= total;
            }
        }
    }
    cout << ans;
}
