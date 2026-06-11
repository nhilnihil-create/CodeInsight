#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(){
    ll n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    ll ans=2*n;
    for(ll i=0;i<n;++i){
        string a=s.substr(i, n-i);
        string b=t.substr(0, n-i);
        if(a==b){
            ans -= n-i;
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}