#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
int dist[220][220];
const int INF = 1001001001;
int n,m,r;
int main()
{
    cin >>n >>m >> r;
    vector<int> p(r);
    rep(i,r)cin >>p[i];
    sort(p.begin(),p.end());
    rep(i,n)rep(j,n)dist[i][j] = INF;
    int ans = 1001001001;
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        dist[a][b] = dist[b][a] = c;

    }
    rep(i,n)rep(j,n)rep(k,n)dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
    do{
        int res = 0;
        rep(i,r-1)res += dist[p[i]-1][p[i+1]-1];
        
        ans = min(ans,res);

    }while(next_permutation(p.begin(),p.end()));
    cout <<ans << endl;



    return 0;
}