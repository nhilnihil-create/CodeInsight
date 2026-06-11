#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;

string s;
ll n;

string dt[4]={"dream","dreamer","erase","eraser"};

bool dfs(ll st){ //stは開始位置
    if(st==n) return true;
    bool ok=false;
    rep(i,4){
        ll m=dt[i].length();
        if(m>n-st) continue;
        bool good=true;
        rep(j,m){
            if(s[st+j]!=dt[i][j]){
                good=false;
            }
        }
        if(good){
            if(dfs(st+m)){
                ok=true;
                break;
            }
        }
    }
    if(ok) return true;
    else return false;
}

int main(){
    cin >> s;
    n=s.length();
    if(dfs(0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
