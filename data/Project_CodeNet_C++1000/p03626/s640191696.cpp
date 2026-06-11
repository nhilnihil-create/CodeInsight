#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int mod = 1000000007;

ll dp[52];

int main(){
    int n; cin >> n;
    vector<string> s(2);
    rep(i,2) cin >> s[i];
    int pos;
    if(s[0][0] != s[1][0]){
        dp[0] = 6;
        dp[1] = 6;
        pos = 2;
    }else{
        dp[0] = 3;
        pos = 1;
    }
    for(int i = pos; i < n; i++){
        if(s[0][i-1] != s[1][i-1]){
            if(s[0][i] != s[1][i]){
                //yoko -> yoko 
                dp[i] = dp[i-1] * 3;
                dp[i] %= mod;
                dp[i+1] = dp[i];
                i++;
            }else{
                //yoko -> tate
                dp[i] = dp[i-1];
            }
        }else{
            if(s[0][i] != s[1][i]){
                //tate -> yoko
                dp[i] = dp[i-1] * 2;
                dp[i] %= mod;
                dp[i+1] = dp[i];
                i++;
            }else{
                //tate -> tate
                dp[i] = dp[i-1] * 2;
                dp[i] %= mod;
            }
        }
    }
    /*
    for(auto elem : dp){
        cout << elem << endl;;
    }
    cout << endl;
    */
    cout << dp[n-1] << endl;
}