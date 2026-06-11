#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll n;
    string s;
    cin>>n>>s;
    ll now=0,mn=0;
    rep(i,n){
        if(s[i]=='(') now++;
        if(s[i]==')') now--;
    }
    if(now>=0){
        rep(i,now) s.push_back(')');
    }else{
        rep(i,-now) s.insert(0,"(");
    }
    now=0;
    rep(i,s.size()){
        if(s[i]=='(') now++;
        if(s[i]==')') now--;
        mn=min(mn,now);
    }
    rep(i,-mn){
        s.push_back(')');
        s.insert(0,"(");
    }
    cout<<s<<endl;
    return 0;
}