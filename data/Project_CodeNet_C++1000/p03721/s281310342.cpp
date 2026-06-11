#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    ll k;
    cin>>n>>k;
    map<int,ll> mp;
    rep(i,n) {
        int temp1,temp2;
        cin>>temp1>>temp2;
        mp[temp1]+=temp2;
    }
    ll cnt=0;
    for (auto v : mp) {
        cnt+=v.second;
        if (k<=cnt) {
            cout<<v.first<<endl;
            return 0;
        }
    }
}
