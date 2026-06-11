#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 10*40+100;
const int inf = 1e9;


int n, ma, mb;
int dp[45][maxn][maxn];


void push(int& x, int y) {
    x=min(x,y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>ma>>mb;


    for (int i=0; i<=n; i++) {
	for (int x=0; x<maxn; x++) {
	    for (int y=0; y<maxn; y++) {
		dp[i][x][y]=inf;
	    }
	}
    }


    
    dp[0][0][0]=0;


    
    for (int i=0; i<n; i++) {
	int a,b,c; cin>>a>>b>>c;
	for (int x=0; x<=10*40; x++) {
	    for (int y=0; y<=10*40; y++) {
		if (dp[i][x][y]<inf) {
		    push(dp[i+1][x+a][y+b],dp[i][x][y]+c);
		}
		push(dp[i+1][x][y],dp[i][x][y]);
	    }
	}
    }


    int res=inf;

    for (int x=1; x<=10*40; x++) {
	for (int y=1; y<=10*40; y++) {
	    int g=__gcd(x,y);
	    int a=x/g;
	    int b=y/g;
	    if (ma==a && mb==b) res=min(res,dp[n][x][y]);
	}
    }


    if (res==inf) out(-1);
    out(res);

    return 0;
}
