#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
vector<vector<int>> dist(210,vector<int>(210,inf));
int main(){
    cout << fixed << setprecision(10);
    int n,m,r;
    cin >> n >> m >> r;
    vector<int> des(r);
    rep(i,r) cin >> des[i];
    rep(i,r) des[i]--;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    rep(k,n){
        rep(i,n){
            rep(j,n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    sort(des.begin(),des.end());
    int ans = inf; 
    do{
        int now = 0;
        rep(i,r-1){
            now += dist[des[i]][des[i+1]];
        }
        ans = min(now,ans);
    }while(next_permutation(des.begin(),des.end()));
    //N!の順列の全探索
    cout << ans << endl;
    return 0;
}