#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;

void dfs(ll a, bool t, const vvll &e, deque<ll> &q, vb &ald){
    if(ald[a]){return;}
    ald[a] = true;
    if(t){
        vll m(0);
        for(auto x: e[a]){
            if(!ald[x]){m.emplace_back(x);}
        }
        if(sz(m)==0){return;}
        else{
            q.push_back(m[0]);
            dfs(m[0], true, e, q, ald);
        }
    }else{
        vll m(0);
        for(auto x: e[a]){
            if(!ald[x]){m.emplace_back(x);}
        }
        if(sz(m)==0){return;}
        else{
            q.push_front(m[0]);
            dfs(m[0], false, e, q, ald);
        }
    }
}

int main(){
    ll N, M; cin >> N >> M;
    vvll e(N+1, vll(0));
    rep(i, 0, M){
        ll a, b; cin >> a >> b;
        e[a].emplace_back(b);
        e[b].emplace_back(a);
    }
    deque<ll> q;
    q.push_back(1);
    vb ald(N+1, false);
    if(sz(e[1])==1){
        dfs(1, true, e, q, ald);
    }
    else{
        ald[1] = true;
        q.push_front(e[1][0]);
        dfs(e[1][0], false, e, q, ald);
        rep(i, 1, sz(e[1])){
            if(!ald[e[1][i]]){
               q.push_back(e[1][i]);
               dfs(e[1][i], true, e, q, ald); 
               break;
            }
        }
    }
    vll ans(0);
    while(!q.empty()){
        ll g = q.front();
        q.pop_front();
        ans.emplace_back(g);
    }
    prtl(sz(ans));
    for(auto x: ans){
        prt(x); prt(" ");
    }
}