#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for(int i =a; i<=b; i++)

ll mod = 1000000007;

int n;
string s;
ll dp[5050][5050];


ll mp(ll x, ll y ){

if(y==0)return 1%mod;
ll u = mp(x, y/2);
u = (u*u)%mod;
if(y%2==1)u = u*x%mod;
return u;
}


int main(){
cin >> n >> s ;

int k = s.size();

dp[0][0]=1;

rep(i, 0, n){

rep(j, 0, i){

    dp[i+1][j+1] =  (dp[i+1][j+1] + dp[i][j]*2%mod)%mod;

    if(j>0){
    dp[i+1][j-1] =  (dp[i][j] + dp[i+1][j-1])%mod;
    }
   // dp[i+1][j-1] = (dp[i][j] + dp[i+1][j-1] )%mod;
    else {
        dp[i+1][0] = (dp[i][0] + dp[i+1][0])%mod;
    }


}


}

cout << dp[n][k]*mp( mp(2, k), mod-2)%mod << endl;

return 0;}
