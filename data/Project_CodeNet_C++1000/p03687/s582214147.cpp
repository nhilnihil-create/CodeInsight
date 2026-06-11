#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;


template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e9+7;


int main(){
    string s;
    cin >> s;
    ll n=s.length();
    ll ans=n-1;
    rep(i,26){
        char c='a'+i;
        bool ok=true;
        string t=s;
        ll cnt=0;
        while(true){
            string u="";
            rep(j,t.length()){
                if(j==t.length()-1){
                    if(t[j]!=c){
                        ok=false;
                        continue;
                    }
                }
                if(t[j]!=c) ok=false;
                if(t[j]==c){
                    u+=c;
                    continue;
                }
                else if(t[j+1]==c){
                    u+=c;
                    continue;
                }
                else{
                    u+=t[j];
                    continue;
                }
            }
            if(ok) break;
            else{
                cnt++;
                t=u;
                u="";
                ok=true;
            }
        }
        ans=min(ans,cnt);
    }
    cout << ans << endl;
    return 0;
    
}