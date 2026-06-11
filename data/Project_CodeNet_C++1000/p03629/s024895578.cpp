#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

string S;
vector<int> p[26];

int dp[200001];
int solve(int n){
    if(dp[n] != INT_MAX) return dp[n];
    rep(i, 26){
        int idx = lower_bound(all(p[i]), n) - p[i].begin();
        if(idx == p[i].size()) dp[n] = 1;
        else dp[n] = min(dp[n], 1 + solve(p[i][idx]+1));
    }
    return dp[n];
}

void print(int n){
    rep(i, 26){
        int idx = lower_bound(all(p[i]), n) - p[i].begin();
        if(idx == p[i].size()){
            cout << (char)('a'+i) << endl;
            exit(0);
        }
        else{
            if(dp[n] == 1 + solve(p[i][idx]+1)){
                cout << (char)('a'+i);
                print(p[i][idx]+1);
            }
        }
    }
}

signed main(){
    cin >> S;
    rep(i, S.size()){
        p[S[i]-'a'].pb(i);
        dp[i] = INT_MAX;
    }
    dp[S.size()] = 1;
    solve(0);
    print(0);
}