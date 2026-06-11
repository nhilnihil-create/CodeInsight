#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, int> LP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool dp[3005][3005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	dp[0][0] = true;
	double ans = -1.0;
	int wat = 0, sug = 0;
	rep(i,f+1){
		rep(j,f+1){
			if(!dp[i][j]) continue;
			if(i+j <= f && i+j != 0){
				double milk = (double)(100 * j) / (double)(i + j);
				if(milk > ans){
					wat = i + j;
					sug = j;
					ans = milk;
				}
			}
			if(i+100*a <= f) dp[i+100*a][j] = true;
			if(i+100*b <= f) dp[i+100*b][j] = true;
			if(i+j+c <= f && j+c <= e*i/100) dp[i][j+c] = true;
			if(i+j+d <= f && j+d <= e*i/100) dp[i][j+d] = true;
		}
	}
	cout << wat << " " << sug << endl;
	return 0;
}