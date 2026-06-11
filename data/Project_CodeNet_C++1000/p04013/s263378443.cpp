//
#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MOD 1000000007
#define PI 3.14159265
#define EPS 1e-9
#define Pi acos(-1.0)
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define clean(arr,val) memset(arr,val,sizeof(arr))
#define forn(i,n) forr(i,0,n)
#define PB push_back
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pll> vpll;

/*CODE START HERE*/

ll dp[55][5000];
int n, a, arr[55], sum;
ll ans;

int main(){
    ios::sync_with_stdio(0);
    clean(dp,0);
    cin >> n >> a;
    sum = 0;
    forn(i,n){
        cin >> arr[i];
        arr[i] = (a-arr[i]);
    }

    sum = a*n+1;

    dp[0][2500]=1;
    dp[0][arr[0]+2500]+=1;
    forr(i,1,n){
        for(int j = 0; j < 5000; j++){
            if (j-arr[i] < 0 || j-arr[i] >= 5000)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = ( dp[i-1][j-arr[i]] + dp[i-1][j] );
        }
    }

    ans =dp[n-1][2500]-1;

    /*forr(i,0,n){
        forr(j,2480,2521){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << ans << "\n";
    return 0;
}