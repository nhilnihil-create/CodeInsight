#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
ll GCD(ll a,ll b) {return b ? GCD(b,a%b):a;}
ll LCM(ll c,ll d){return c/GCD(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
V<int> g[100005];
deque<int> deq;
bool used[100005];
void solve(int cur,bool front){
    bool ok=true;
    for(int v:g[cur]){
        if(used[v])continue;
        if(front)deq.push_front(v+1);
        else deq.push_back(v+1);
        used[v]=true;
        solve(v,front);
        ok=false;
        break;
    }
    if(cur==0){
        for(int v:g[cur]){
        if(used[v])continue;
        used[v]=true;
        deq.push_back(v+1);
        solve(v,false);
        break;
       }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    deq.push_back(1);
    used[0]=true;
    solve(0,1);
    cout<<deq.size()<<"\n";
    while(deq.size()){
        cout<<deq.front()<<(deq.size()==1?"\n":" ");
        deq.pop_front();
    }
}