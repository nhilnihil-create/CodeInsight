// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};


int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    ll n;
    ll a,b;
    ll k,t;
    string str;
    ll h,w;
    cin>>h>>w;
    string s[h];
    rep(i,h){
        cin>>s[i];
    }
    map<char,ll> mp;
    set<char> se;
    ll f=0;
    ll sum=0;
    rep(i,h)rep(j,w) mp[s[i][j]]++;
    rep(i,h)rep(j,w) se.insert(s[i][j]);
    if(w%2&&h%2){
        ll okf=0;
        ll odds=0;
        if(h!=1&&w!=1){
            for(auto itr=se.begin();itr!=se.end();++itr){
                if(mp[*itr]%2)sum++;
                if(mp[*itr]%2==0&&mp[*itr]%4==2) odds++;
                if(mp[*itr]>=4) okf=1;
            }
        }else if(w==1&&h==1) okf=1;
        else{
            for(auto itr=se.begin();itr!=se.end();++itr){
                if(mp[*itr]%2)sum++;
                if(mp[*itr]>=2) okf=1;
            }
        }
        if(sum>1||okf==0||odds>h/2+w/2) f=1;
    }else if(w%2==0&&h%2==0){
        ll okf=0;
        for(auto itr=se.begin();itr!=se.end();++itr){
            if(mp[*itr]%4)f=1;
        }
       // f=1;
    }else{
        ll okf=0;
        ll odds=0;
        if(h!=1&&w!=1){
            for(auto itr=se.begin();itr!=se.end();++itr){
                if(mp[*itr]%2)sum++;
                if(mp[*itr]%2==0&&mp[*itr]%4==2) odds++;
                if(mp[*itr]>=4) okf=1;
            }
        }else if(w==1&&h==1) okf=1;
        else{
            for(auto itr=se.begin();itr!=se.end();++itr){
                if(mp[*itr]%2)sum++;
                if(mp[*itr]>=2) okf=1;
            }
        }
        if(h%2){
        if(sum>1||okf==0||odds>w/2) f=1;
        }else{
        if(sum>1||okf==0||odds>h/2) f=1;
        }
    }

    if(f) No;
    else Yes;

    return 0;
}
