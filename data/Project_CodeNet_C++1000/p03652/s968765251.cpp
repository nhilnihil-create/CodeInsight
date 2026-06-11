#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define ll long long int

ll const MOD = 1000000007;
ll const INF = (long long int)1 << 61;

ll mypow(ll x,ll n){
    ll ret = 1;
    while(n > 0){
        if(n&1){
            ret = (ret*x)%MOD;
        }
        x = (x*x)%MOD;
        n >>= 1;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >> m;

    vector<vector<ll>> a(n,vector<ll>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    ll ans = n;

    vector<ll> id(n,0);
    vector<bool> used(m+1,false);

    for(int i = 0; i < m; i++){
        vector<ll> count(m+1,0);
        for(int j = 0; j < n; j++){
            count[a[j][id[j]]]++;
        }
        ll mm = 0;
        ll mn = 0;
        for(int j = 0; j <= m; j++){
            if(count[j] > mn){
                mn = count[j];
                mm = j;
            }
        }
        ans = min(ans,mn);
        used[mm] = true;
        for(int j = 0; j < n; j++){
            while(id[j] < m && used[a[j][id[j]]]){
                id[j]++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}