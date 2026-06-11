#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (int)(n); i++)
const ld pi=3.14159265358979323846;
 
int main() {
    ll n,l;
    cin>>n>>l;
    vector<string> v;
    rep(i,n){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    string ans="";
    rep(i,n){
        ans+=v.at(i);
    }
    cout<<ans<<endl;
}