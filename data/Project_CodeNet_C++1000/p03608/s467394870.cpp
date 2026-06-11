#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int INF = 1e9;
vector<vector<int> > d(205, vector<int>(205));
int main(void){
    int n, m, r;
    cin>>n>>m>>r;
    vector<int> vr(r);
    rep(i, r) cin>>vr[i];
    sort(vr.begin(), vr.end());
    rep(i, n)rep(j, n) d[i][j] = INF;
    rep(i, n) d[i][i] = 0;

    rep(i, m){
        int a, b, c;
        cin>>a>>b>>c;
        --a;--b;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }

    rep(k, n)rep(i, n)rep(j, n){
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    }
    int ans = INF;
    do{
        int tmp = 0;
        rep(i, vr.size()-1){
            tmp += d[vr[i]-1][vr[i+1]-1];
        }
        ans = min(ans, tmp);
    }while(next_permutation(vr.begin(), vr.end()));
    cout<<ans<<endl;
    return 0;
}