#include <bits/stdc++.h>
using namespace std;
#define __ <<" "<<
#define ___ <<" "
#define bash push_back
#define ALL(x) x.begin(),x.end()
//#define int long long
struct IoSetup {
    IoSetup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
}IoSetup;

typedef long long ll;
typedef pair < int , int >  pii;
static const signed int INF = 0x3f3f3f3f;
static const signed long long LINF = 0x3f3f3f3f3f3f3f3fLL;
static const signed int SMOD = 1000000007;
static const signed int NMOD = 998244353;
static const signed int dx[]={1,0,-1,0,1,1,-1,-1};
static const signed int dy[]={0,-1,0,1,-1,1,-1,1};

bool inside(int x,int y,int w,int h){return (x>=0 && y>=0 && x<w && y<h);}
template<class T>bool chmax(T &a, const T&b){if(a<b)return(a=b,1);return 0;}
template<class T>bool chmin(T &a, const T&b){if(b<a)return(a=b,1);return 0;}

int n;
int a[50], b[50], c[50];

int ma, mb;

int dp[50][500][500];

signed main() {
	
	cin >> n >> ma >> mb;

	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	int ans = INF;
	memset(dp, 0x3f, sizeof(dp));

	/*
	  for(int i = 0; i <= 400; i++) {
	  for(int j = 0; j <= 400; j++) {
	  dp[0][i][j] = 0;
	  }
	  }
	*/

	for(int i = 0; i < n; i++) {
		dp[i][0][0] = 0;
		for(int j = 0; j <= 400; j++) {
			for(int k = 0; k <= 400; k++) {
				dp[i+1][j][k] = dp[i][j][k];
				
				if(j - a[i] >= 0 && k - b[i] >= 0) {
					
					chmin(dp[i+1][j][k], dp[i][j-a[i]][k-b[i]] + c[i]);
					
					if(j * mb == k * ma) { 
						chmin(ans, dp[i+1][j][k]);
					}
				}
			}
		}
	}

	if(ans == INF) ans = -1;
			
	cout << ans << endl;
	
	
    return 0;
}

