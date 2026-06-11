#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

LL n,k;
vector<LL> a;

bool solve(LL y){
    vector<vector<bool>> dp(n+1,vector<bool>(k,false));
    dp[0][0] = true;
    for(int i = 1; i < n+1; i++){
        if(i == y+1){
            for(int j = 0; j < k; j++){
                dp[i][j] = dp[i-1][j];
            }
        }else{
            for(int j = 0; j < k; j++){
                dp[i][j] = dp[i-1][j];
                if(j - a[i-1] >= 0 && dp[i-1][j-a[i-1]]){
                    dp[i][j] = true;
                }
            }
        }
    }
    LL ind = 0;
    for(int i = k-1; i >= 0; i--){
        if(dp[n][i]){
            ind = i;
            break;
        }
    }
    return (ind+a[y] >= k);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        LL x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(),a.end());

    LL ng = -1;
    LL ok = n;
    while(abs(ok-ng) > 1){
        LL middle = (ok+ng)/2;
        bool t = solve(middle);
        if(t){
            ok = middle;
        }else{
            ng = middle;
        }
    }

    cout << ng + 1 << endl;

    return 0;
}