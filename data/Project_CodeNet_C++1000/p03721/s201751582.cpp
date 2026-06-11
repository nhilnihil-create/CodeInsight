#include <bits/stdc++.h>
#define N 1005
#define INF 0x3f3f3f3f 
#define mod 1000000007
using namespace std;
typedef long long ll;
ll ans;
 
int main(){
    ll n, k;
    cin >> n >> k;
    map <int,ll> mp;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        mp[a]+=b;
    }
    ll cntr = 0;
    for(auto i:mp){
        cntr+=i.second;
        if(cntr >= k){
            cout << i.first;
            return 0;
        }
    }
    return 0;
}
