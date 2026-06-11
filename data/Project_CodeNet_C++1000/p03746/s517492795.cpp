#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
vector<int> E[100001];
ll N,M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    deque<int> d;
    set<int> s;
    int a,b;
    rep(i,0,M){
        cin>>a>>b;
        E[a].pb(b);
        E[b].pb(a);
    }
    d.push_front(a);
    d.pb(b);
    s.insert(a);
    s.insert(b);
    for(;;){
        bool t=true;
        rep(i,0,sz(E[b])){
            if(s.find(E[b][i])==s.end()){
                b=E[b][i];
                d.pb(b);
                s.insert(b);
                t=false;
                break;
            }
        }
        if(t) break;
    }
    for(;;){
        bool t=true;
        rep(i,0,sz(E[a])){
            if(s.find(E[a][i])==s.end()){
                a=E[a][i];
                d.push_front(a);
                s.insert(a);
                t=false;
                break;
            }
        }
        if(t) break;
    }
    cout <<sz(d)<<"\n";
    rep(i,0,sz(d)){
        if(i==sz(d)-1) cout <<d[i]<<"\n";
        else cout <<d[i]<<" ";
    }
}