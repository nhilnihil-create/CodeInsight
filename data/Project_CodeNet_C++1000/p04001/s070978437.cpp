#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for(ll i=(ll)(srt); i<(ll)(end); i++)

int main(){
    string s;
    cin>>s;
    int n = s.size()-1;
    ll ans=0;

    for(int i=0;i<(1<<n);i++){

        ll ver = s[0] - '0';
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                ans+=ver;
                ver=0;
            }
            ver=ver*10+s[j+1]-'0';
        }

        ans+=ver;
    }

    cout<<ans<<endl;
    return 0;
}