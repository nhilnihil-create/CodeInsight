
// author-Shivam gupta

#include <bits/stdc++.h>


using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))

#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)

#define IN(A, B, C) assert( B <= A && A <= C)

#define MP make_pair
#define FOR(i,a) for(int i=0;i<a;i++)

#define FOR1(i,j,a) for(int i=j;i<a;i++)

#define EB emplace_back

#define INF (int)1e9

#define EPS 1e-9

#define PI 3.1415926535897932384626433832795

#define MOD 1000000007

#define read(type) readInt<type>()
#define max1 1000008
#define out(x) cout<<x<<'\n'
#define out1(x) cout<<x<<" "
#define END cout<<'\n'
typedef long int li;

typedef unsigned long int uli;

typedef long long int ll;

typedef unsigned long long int  ull;


void fast(){
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}

int main() {
 int n,a;
 cin>>n>>a;
 int x[n];
 FOR(i,n){
 cin>>x[i];}
 ll dp[n+1][n+1][2501];
    FOR(i,n+1)
    {
    FOR(j,n+1)
        {
    FOR(k,n*a + 1)
        {
        dp[i][j][k] = 0;
        }
        }
    }
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            for(ll k=0;k<=2500;k++)
            {
                if(j == 0 || (k - x[i-1]) < 0)
                {
                    dp[i][j][k] = dp[i-1][j][k];
                }
                else
                {
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-x[i-1]];
                }
            }
        }
    }

    ll res = 0;
    for(int k = 1; k <= n; k++)
    {
        res += dp[n][k][k*a];
    }
    out(res);

}

