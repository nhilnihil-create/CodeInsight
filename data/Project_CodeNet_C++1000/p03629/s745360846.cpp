#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int prv[26][200010];
int dp[200010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    string S, K; cin >> K;
    rep(i, K.length()) S += K[K.length() - 1 - i];
    //cout << S << endl;
    rep(i, 26) rep(j, 200010) prv[i][j] = 0;
    rep(i, 200010) dp[i] = INF;
    rep(i, S.length()) {
        rep(j, 26) {
            prv[j][i + 2] = prv[j][i + 1];
        }
        prv[S[i] - 'a'][i + 2] = i + 1;
    }
    /*
    rep(i, S.length()) {
        cout << i + 1 << " " << S[i] << " ";
        rep(j, 26) {
            cout << prv[j][i + 1] << " ";
        }
        cout << endl;
    }
    //*/
    dp[0] = 0;
    rep(i, S.length() + 1) {
        rep(j, 26) {
            dp[i + 1] = min(dp[i + 1], dp[prv[j][i + 1]] + 1);
        }
        //cout << i + 1 << " " << dp[i + 1] << endl;
    }
    int i = S.length() + 1;
    //cout << dp[i] << endl;
    string A; 
    while(i > 0){
        rep(j, 26) {
            //cout << "*" << i << " " << dp[i] << " " << prv[j][i] << endl;
            if (dp[i] == dp[prv[j][i]] + 1) {
                A += (char)(j + 'a');
                i = prv[j][i];
                break;
            } else {
                //cout << dp[i] << " " <<  dp[prv[j][i]] << endl;
            }
        }
        //cout << A << endl;
    }
    cout << A << endl;
   


    return 0;
}
