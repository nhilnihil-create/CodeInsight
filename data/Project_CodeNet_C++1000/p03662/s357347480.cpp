#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6,black=1,white=2;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt,ans,a[ohara],b[ohara],c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool bvisited[ohara],wvisited[ohara],fl;
struct edge{int to,cost;};
unordered_map<ll,ll> bmp;
unordered_map<ll,ll> wmp;
vector<ll> graph[ohara];

//-------------------------↓↓↓↓↓↓------------------------

void dfs1(ll now,ll depth){
    if(bvisited[now])return;
    bvisited[now]=true;
    bmp[now]=depth;
    rep(i,Size(graph[now])){
        dfs1(graph[now][i],depth+1);
    }
}

void dfs2(ll now,ll depth){
    if(wvisited[now])return;
    wvisited[now]=true;
    wmp[now]=depth;
    rep(i,Size(graph[now])){
        dfs2(graph[now][i],depth+1);
    }
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    rep(i,n-1)cin>>a[i]>>b[i],a[i]--,b[i]--;
    rep(i,n-1){
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }
    dfs1(0LL,0LL);
    dfs2(n-1,0LL);
    ll wp=0,bp=0;
    rep(i,n){
        if(bmp[i]<=wmp[i])bp++;
        else wp++;
    }
    if(wp>=bp)Cout("Snuke");
    else Cout("Fennec");
    return 0;
}
