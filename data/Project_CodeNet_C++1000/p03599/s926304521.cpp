#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool dp[3500][3500];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	dp[0][0] = true;
	double milk = -1;
	int water = 0, sugar = 0;
	rep(i,f+1){
		rep(j,f+1){
			if(!dp[i][j]) continue;
			if(i+j != 0){
				double thismilk = (double)(100*j) / (double)(i+j);
				if(thismilk > milk){
					milk = thismilk;
					water = i;
					sugar = j;
				}
			}
			if(i+j+a*100 <= f) dp[i+a*100][j] = true;
			if(i+j+b*100 <= f) dp[i+b*100][j] = true;
			if(i+j+c <= f && j+c <= e*(i/100)) dp[i][j+c] = true;
			if(i+j+d <= f && j+d <= e*(i/100)) dp[i][j+d] = true;
		}
	}
	cout << water+sugar << " " << sugar << endl;
	return 0;
}
