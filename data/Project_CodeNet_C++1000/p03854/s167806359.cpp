#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[100010];//i文字目まで作成可能
int main()
{
    string S;
    cin >> S;
    string A[4] = {"dream", "dreamer", "erase", "eraser"};
    int N = S.size();
    rep(i, 5) dp[i] = 0;
    dp[0] = 1;
    rep2(i, 5, N+1)
    {
        //cout << S << endl;
        if(i-5 >= 0 && dp[i-5])
        {
            auto x = S.substr(i-5, 5);
            if(x == A[0] || x == A[2]){ 
                dp[i] = 1;
            }
        }
        if(i-6 >= 0 && dp[i-6])
        {
            auto x = S.substr(i-6, 6);
            if(x == A[3]){
                 dp[i] = 1;
            }
        }
        if(i-7 >= 0 && dp[i-7])
        {
            auto x = S.substr(i-7, 7);
            if(x == A[1])
            {
                dp[i] = 1;
            } 
        }
    }
    if(dp[N]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}