#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

int main()
{
	int n, ma, mb;
	cin >> n >> ma >> mb;
	vector<int> a(n), b(n), c(n);
	rep(i,n){
		cin >> a[i] >> b[i] >> c[i];
	}
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(500, vector<int>(500, inf)));
	dp[0][0][0] = 0;
	rep(i,n){
		rep(j,405){
			rep(k,405){
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
				dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
			}
		}
	}
	int ans = inf;
	rep2(i,1, 405)
	{
		rep2(j,1,405){
			if (i * mb == j * ma)
				ans = min(ans, dp[n][i][j]);
		}
	}
	if(ans == inf)
		ans = -1;
	cout << ans << endl;
	return 0;
}


