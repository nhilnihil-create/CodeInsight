#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<double,double> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;
const LL INF=1<<30;


LL dp[5001][5001];

LL fpow(LL a, LL n){
    int x = 1;
    while(n > 0){
        if(n&1){
            x=x*a%mod;
        }
        a=a*a%mod;
        n >>= 1;
    }
    return x;
}

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    dp[0][0]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i+1][j+1]=(dp[i+1][j+1]+2*dp[i][j])%mod;
            if(j==0) dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
            else dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%mod;
        }
    }
    cout << (dp[N][s.length()]*fpow(fpow(2,s.length()),mod-2))%mod << endl;
    return 0;
}