#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define endl "\n"
using ll=long long;
using ld=long double;
using namespace std;
ll mod= 1e9+7;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

main(){
    string s;
    cin>>s;
    ll k;
    cin>>k;
    char p;
    while(k>0){
        rep(i,0,s.length()){
            if(k<=0)break;
            char x=s[i];
            if(x=='a')continue;
            ll g=s[i]-0;
            g+=k;
            if(g>=0x7B){s[i]='a';k-='{'-x;}
        }
        p=s[s.length()-1];
        if(k>0){
            ll g=p-0;
            g+=k;
            if(g>=0x7B){
                ll f=k-(p-0x61);
                f=k%26;
                s[s.length()-1]=0x61+f;
            }
            else s[s.length()-1]=p+k;
            k=0;
        }
    }
    cout<<s;
}