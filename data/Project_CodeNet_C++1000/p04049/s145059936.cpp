#include <bits/stdc++.h>
#define F(i,n) for (int i=1; i<=(int)n; i++)
#define FF(i,n) for (int i=0; i<(int)n; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pi pair < int , int >
#define re(x) (int)x.size()
#define y1 u228
#define vi vector<int>
using namespace std;
typedef long long ll;
const int N = 100010;
const int big = 2e9;
const int md = 1e9 + 7;
int n,k,ans,tex,d1[N],d2[N];
vi p[N];
void dfs(int v,int pr,int kol){
    if (kol>k/2) tex++;
    FF(j,re(p[v])){
        int u=p[v][j];
        if (u==pr) continue;
        dfs(u,v,kol+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
//    freopen("input.txt","r",stdin);
    cin>>n>>k;
    F(i,n-1){
        int a,b;
        cin>>a>>b;
        p[a].pb(b);
        p[b].pb(a);
        d1[i]=a; d2[i]=b;
    }
    ans=big;
    if (k%2==0){
        F(i,n){
            tex=0;
            dfs(i,-1,0);
            ans=min(ans,tex);
        }
        cout<<ans;
        return 0;
    }
    F(i,n-1){
        tex=0;
        dfs(d1[i],d2[i],0);
        dfs(d2[i],d1[i],0);
        ans=min(ans,tex);
    }
    cout<<ans;
    return 0;
}





