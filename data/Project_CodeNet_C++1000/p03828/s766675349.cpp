#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;
const int MOD=1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i = 0; i < n; i++) {
        int refi=i+1;
        int d=2;
        while(refi>1){
            if(refi%d==0){
                refi/=d;
                mp[d]++;
            }
            else d++;
        }
        mp[refi]++;
    }
    ll ans=1;
    for(auto itr = mp.begin(); itr!=mp.end() ; itr++) {
        int t=itr->second;
//        cout << itr->first << " " << t << "\n";
        if(itr->first!=1) ans=ans*(t+1)%MOD;
    }
    cout << ans << "\n";

    return 0;
}