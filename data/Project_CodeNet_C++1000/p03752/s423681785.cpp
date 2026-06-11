#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    ll ans = INF;
    for(int i = 0; i < (2<<n); i++){
        ll height = a[0];
        ll cnt = 0;
        ll k_num = 0;
        for(int j = 0; j < n-1; j++){
            if(((i>>j)&1) == 1) k_num++;
        }
        if(k_num != k-1) continue;

        for(int j = 1; j < n; j++){
            if(((i>>(j-1))&1) == 0) {
                height = max(height, a[j]);
                continue;
            }
            if(height >= a[j]){
                cnt += (height+1)-a[j];
                height++;
            } else {
                height = a[j];
            }
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;


    return 0;
}