#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string s; cin>>s;
    map<char,ll> mp;
    rep(i,s.size()) mp[s[i]]++;
    rep(i,26){
        if(!mp['a'+i]){
            cout<<(char)('a'+i)<<endl;
            return 0;
        } 
    }
    cout<<"None"<<endl;
    return 0;
}