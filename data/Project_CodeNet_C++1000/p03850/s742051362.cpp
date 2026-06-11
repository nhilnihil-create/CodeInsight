#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

ll dp[100009][3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, x;
    string s;
    cin>>N>>x;
    mem(dp,0xcf);
    dp[0][0] = x;
    rep(i,N-1){
        cin>>s>>x;
        ll T[3];
        if(s=="+"){
            T[0]=dp[i][0];
            T[1]=dp[i][1];
            T[2]=dp[i][2];
        }else{
            T[0]=T[2]=dp[i][1];
            T[1]=max(dp[i][0],dp[i][2]);
        }
        dp[i+1][2]=T[2]+x;
        dp[i+1][1]=max(dp[i+1][2],T[1]-x);
        dp[i+1][0]=max(dp[i+1][1],T[0]+x);
    }
    cout1(*max_element(dp[N-1],dp[N-1]+3));
}