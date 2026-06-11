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

ll dp[55][55][2505] = {0};

int main()
{
	ll n, a;
	cin >> n >> a;
	vector<ll> x(n);
	rep(i, n) cin >> x[i];
	dp[0][0][0] = 1;
	rep(i, n)
	{
		rep(j,51){
			rep(k,2505){
				dp[i + 1][j][k] += dp[i][j][k];
				if (k - x[i] >= 0)
					dp[i + 1][j+1][k] += dp[i][j][k - x[i]];

			}
		}
	}
	ll ans = 0;
	rep(j,n+1){
        rep(k,2505){
            if(a*j==k&&k!=0)ans+=dp[n][j][k];
        }
    }
	cout << ans << endl;

	return 0;
}