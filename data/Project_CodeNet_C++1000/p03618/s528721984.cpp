#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000009
const long long INF = 1LL<<60;

int main() {
    string s;
    cin>>s;
    ll n=s.length();

    vector<ll> cnt(26,0);
    rep(i,n) cnt[s[i]-'a']++;
    ll ans=n*(n-1)/2;
    rep(i,26){
        if(cnt[i]>=2) ans-=cnt[i]*(cnt[i]-1)/2;
    }
    cout<<ans+1<<endl;
}