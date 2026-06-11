#include<iostream>
#include<vector>
#include<map>

using namespace std;
using DP = map<pair<int, int>, long>;
vector<int> x;
map<pair<int, int>, bool> seen;

long calculate(DP& dp, int n, int s){
    auto p = make_pair(n, s);
    if (seen[p] == true) return dp[p];
    if (n == 0 && s == 0){
        dp[p] = 1;
    }else if (n > 0){
        dp[p] = calculate(dp, n-1, s) + calculate(dp, n-1, s-x[n-1]);
    }else{
        dp[p] = 0;
    }
    seen[p] = true;
    return dp[p];
}

int main(){
    int N, A;
    cin >> N >> A;
    for (int i=0; i<N; i++){
        int a; cin >> a;
        x.push_back(a-A);
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    DP dp;
    
    long ans = 0;
    ans = calculate(dp, N, 0);
    cout << ans-1 << endl;
    return 0;
}