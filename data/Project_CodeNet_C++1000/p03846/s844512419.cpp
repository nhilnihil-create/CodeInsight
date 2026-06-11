#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    cin>>n;
    ll ans=1;
    map<int,int> mp;
    rep(i,n) {
        int temp;
        cin>>temp;
        mp[temp]++;
    }
    for (auto v:mp) {
        if (v.first==0&&v.second!=1) {
            ans=0;
            break;
        } else if(v.first==0) continue;
        else if(v.second!=2) {
            ans=0;
            break;
        } else {
            ans*=2;
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
}
