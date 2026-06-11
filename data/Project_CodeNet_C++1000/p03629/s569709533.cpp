#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <set>
#include <cmath>
#include <cassert>
using namespace std;
#define INF 1<<30

vector<int> pos[26];
int dp[200002];

int func(int i){
    if(dp[i] != INF) return dp[i];
    for(int j=0; j<26; j++){
        auto itr = lower_bound(pos[j].begin(), pos[j].end(), i+1);
        if(itr == pos[j].end()){
            dp[i] = 1;
            break;
        }else{
            int k = *itr;
            dp[i] = min(dp[i], 1 + func(k));
        }
    }
    return dp[i];
}

int main(){
    string A;
    cin >> A;
    int N = A.size();

    {
        bool vis[26];
        fill_n(vis, 26, false);
        for(int i=0; i<N; i++)
            vis[A[i]-'a'] = true;
        for(int i=0; i<26; i++)
            if(!vis[i]){
                char ans = 'a'+i;
                cout << ans << endl;
                return 0;
            }
    }

    for(int i=0; i<N; i++)
        pos[A[i]-'a'].push_back(i);

    fill_n(dp, N, INF);
    for(int i=0; i<N; i++)
        dp[i] = func(i);

    string ans = "";
    int cur = -1;
    bool ok = false;
    while(!ok){
        for(int i=0; i<26; i++){
            auto itr = lower_bound(pos[i].begin(), pos[i].end(), cur+1);
            if(itr == pos[i].end()){
                ok = true;
                char c = 'a'+i;
                ans.push_back(c);
                break;
            }
        }
        if(ok) break;

        int i_best;
        int k_best;
        int dp_best = 1<<30;
        for(int i=25; i>=0; i--){
            auto itr = lower_bound(pos[i].begin(), pos[i].end(), cur+1);
            int k = *itr;
            if(dp[k] <= dp_best){
                dp_best = dp[k];
                k_best = k;
                i_best = i;
            }
        }
        cur = k_best;
        char c = 'a'+i_best;
        ans.push_back(c);
    }
    cout << ans << endl;
    return 0;
}
