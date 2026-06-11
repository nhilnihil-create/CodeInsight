#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
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
const int INF=10000;
vector<int> E[2000];
int d[2000][2000];
int res, MAX;
void dfs(int k,int x){
    MAX=max(MAX,res);
    d[k][x]=res;
    res++;
    rep(i,0,E[x].size()){
        if(d[k][E[x][i]]==INF) dfs(k,E[x][i]);
    }
    res--;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,K;
    cin>>N>>K;
    int A[N-1],B[N-1];
    rep(i,0,N-1){
        cin>>A[i]>>B[i];
        E[A[i]-1].pb(B[i]-1);
        E[B[i]-1].pb(A[i]-1);
    }
    rep(i,0,N){
        rep(j,0,N) d[i][j]=INF;
    }
    MAX=0;
    rep(i,0,N){
        res=0;
        dfs(i,i);
    }
    if(MAX<=K) cout <<0<<"\n";
    else{
        if(K%2){
            int ans=0;
            rep(i,0,N-1){
                set<int> s;
                rep(j,0,N){
                    if(d[A[i]-1][j]<=K/2) s.insert(j);
                    if(d[B[i]-1][j]<=K/2) s.insert(j);
                }
                int t=s.size();
                ans=max(ans,t);
            }
            cout <<N-ans<<"\n";
        }
        else{
            int ans=0;
            rep(i,0,N){
                int res=0;
                rep(j,0,N){
                    if(d[i][j]<=K/2) res++;
                }
                ans=max(ans,res);
            }
            cout <<N-ans<<"\n";
        }
    }
}