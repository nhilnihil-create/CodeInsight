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
    
    ll n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());

    ll diameter = a.back();
    a.push_back(INF);
    bool odd = (bool)(diameter&1);
    ll radius = diameter/2 + (odd ? 1 : 0 );

    bool first = true;

    if(a[0] != radius){
        cout << "Impossible" << endl;
        return 0;
    }
    int prev = radius - 1;
    for(int i = 0; i < n; i++){
        int count = 0;
        while(a[i] == a[i+1]){
            count++;
            i++;
        }
        if(first){
            first = false;
            
            if(odd){
                if(count > 1){
                    cout << "Impossible" << endl;
                    return 0;
                }
            }else{
                if(count > 0){
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }else{
            if(count < 1){
                cout << "Impossible" << endl;
                return 0;
            }
        }
        if(prev+1 != a[i]){
            cout << "Impossible" << endl;
            return 0;
        }
        prev = a[i];
    }

    cout << "Possible" << endl;

    return 0;
}