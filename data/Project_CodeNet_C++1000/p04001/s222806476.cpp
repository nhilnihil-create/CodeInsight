#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF (1<<18)



int main() {
    string str;
    cin>>str;

    int l = str.length();
    int s[l];
    rep(i,l) s[i] = str[l-i-1]-'0';


    ll ans = 0; 
    ans += s[0]*(1<<l-1);

    rep(i,1 << l-1 ){
        int b = -1;
        rep(j,l-1){
            if((i >> j)&1) b = j;
            ans += s[j+1]*pow(10,j-b);
        }
    }

    cout<<ans<<endl;
    return 0;
}