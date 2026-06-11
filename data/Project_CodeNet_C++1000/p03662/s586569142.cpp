#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const int mod=1000000007;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};


//#define int ll

vector <int> x[200009];
int n,a,b;
int dist1[200009],dist2[200009];
int cnt1=0,cnt2=0;

void dfs1(int pos,int depth){
    if(dist1[pos]!=-1)return;
    dist1[pos]=depth;
    rep(i,0,x[pos].size()){
        dfs1(x[pos][i],depth+1);
    }
}

void dfs2(int pos,int depth){
    if(dist2[pos]!=-1)return;
    dist2[pos]=depth;
    rep(i,0,x[pos].size()){
        dfs2(x[pos][i],depth+1);
    }
}

signed main(){
    cin>>n;
    rep(i,0,200009)dist1[i]=dist2[i]=-1;
    rep(i,0,n){
        cin>>a>>b;
        x[a].pb(b);
        x[b].pb(a);
    }
    
    dfs1(1,0);dfs2(n,0);
    rep(i,1,n+1){
        if(dist1[i]<=dist2[i])cnt1++;
        else cnt2++;
    }
    
    if(cnt1>cnt2)cout<<"Fennec"<<endl;
    else cout<<"Snuke"<<endl;
    return 0;
}