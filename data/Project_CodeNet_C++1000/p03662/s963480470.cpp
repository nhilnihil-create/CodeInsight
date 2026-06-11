#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,n,m) for(ll i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) for(ll i=(n);i>=0;i--)
#define all(vec) vec.begin(),vec.end()
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using P=pair<ll,ll>;
using PP=pair<ll,P>;
using vp=vector<P>;
using vpp=vector<PP>;
using vs=vector<string>;
#define fi first
#define se second
#define pb push_back
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
const ll MOD=1000000007LL;
const int INF=1<<30;
const ll LINF=1LL<<60;
int main(){
    int V;
    cin>>V;
    vvi G(V);
    REP(i,V-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    vi a(V,INF);
    vi b(V,INF);
    queue<int> que;
    que.push(0);
    a[0]=0;
    while(que.size()){
        int p=que.front();que.pop();
        REP(i,G[p].size()){
            int v=G[p][i];
            if(a[v]>a[p]+1){
                a[v]=a[p]+1;
                que.push(v);
            }
        }
    }
    que.push(V-1);
    b[V-1]=0;
    while(que.size()){
        int p=que.front();que.pop();
        REP(i,G[p].size()){
            int v=G[p][i];
            if(b[v]>b[p]+1){
                b[v]=b[p]+1;
                que.push(v);
            }
        }
    }
    int p=0,q=0;
    REP(i,V){
        if(a[i]<=b[i]){
            p++;
        }else{
            q++;
        }
    }
    if(p>q){
        cout<<"Fennec"<<endl;
    }else{
        cout<<"Snuke"<<endl;
    }
    return 0;
}