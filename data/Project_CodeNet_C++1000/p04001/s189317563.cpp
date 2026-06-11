#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    string S; cin>>S;
    ll ans=0;
    for(int bit=0;bit<(1<<S.size()-1);bit++){
        ll now=0;
        for(int i=0;i<S.size();i++){
            now=now*10+S[i]-'0';
            if(bit & 1<<i){
                ans+=now;
                now=0;
            }
        }
        ans+=now;
    }
    cout<<ans;
    return 0;
}