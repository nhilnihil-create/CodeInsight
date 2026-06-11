#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N, K; cin >> N >> K;
    vector<int> a(N);
    REP(i,N) cin >> a[i];
    vector<vector<bool>> dp1(N+1,vector<bool>(K,false)), dp2(N+1,vector<bool>(K,false));
    vector<vector<int>> v1(N+1),v2(N+1);
    // dp1[i][j] 1番目からi番目までのカードを使ってjをつくることができるかどうか
    // dp2[i][j] N-i+1番目からN番目までのカードを使ってjをつくることができるかどうか
    dp1[0][0] = true; v1[0].push_back(0);
    dp2[0][0] = true; v2[0].push_back(0);
    REP(i,N)REP(j,K){
        if(a[i]>j) {
            dp1[i+1][j] = dp1[i][j];
            if(dp1[i+1][j])v1[i+1].push_back(j);
        }
        else {
            dp1[i+1][j] = (dp1[i][j] || dp1[i][j-a[i]]);
            if(dp1[i+1][j])v1[i+1].push_back(j);
        }
        if(a[N-i-1]>j) {
            dp2[i+1][j] = dp2[i][j];
            if(dp2[i+1][j])v2[i+1].push_back(j);
        }
        else {
            dp2[i+1][j] = (dp2[i][j] || dp2[i][j-a[N-i-1]]);
            if(dp2[i+1][j])v2[i+1].push_back(j);
        }
    }
    int cnt = 0;
    FOR(i,1,N+1){
        bool flag = false;
        for(auto x:v1[i-1]){
          	int ind = lower_bound(all(v2[N-i]),K-a[i-1]-x)-v2[N-i].begin();
            if(ind != v2[N-i].size() && v2[N-i][ind] <K-x) {flag = true;break;}
        }
        if(!flag) cnt ++;
    }

    cout << cnt << endl;
    return 0;
}