#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;
int dp[50][500][500];

void chmin(int &a, int b){if (a > b) a = b;}

int main(){
    int n, ma, mb; cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    rep(i,50)rep(j,500)rep(k,500) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i,n)rep(wa,500)rep(wb,500){
        if(dp[i][wa][wb]==INF) continue;
        chmin(dp[i+1][wa][wb], dp[i][wa][wb]);
        chmin(dp[i+1][wa+a[i]][wb+b[i]], dp[i][wa][wb] + c[i]);
    }
    int res = INF;
    for(int wa = 1; wa < 500; wa++){
        for(int wb = 1; wb < 500; wb++){
            if(wa*mb != wb*ma) continue;
            chmin(res, dp[n][wa][wb]);
        }
    }
    if(res < INF) cout << res << endl;
    else cout << -1 << endl;
}