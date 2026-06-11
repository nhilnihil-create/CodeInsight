#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> edge[N];
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> dp(N);
    for(int i = 0;i < edge[0].size(); i++){
        dp[edge[0][i]]++;
    }
    for(int i = 0;i < edge[N-1].size(); i++){
        dp[edge[N-1][i]]++;
    }
    bool judge = false;
    for(int i = 1;i < N-1;i++){
        if(dp[i] >= 2) judge = true;
    }
    string ans = "";
    if(judge) ans = "POSSIBLE";
    else ans = "IMPOSSIBLE";
    cout << ans << endl;
    return 0;
}
