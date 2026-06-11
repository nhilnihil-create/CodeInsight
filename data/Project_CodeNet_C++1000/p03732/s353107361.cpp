#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#define PI 3.14159265359
typedef long long ll;
const int MOD = 1e9+7;
const ll LLINF = 7e18;
using namespace std;

int w[4];
vector<int> v[4];
vector<ll> sum[4];

int main(){
	ll n, w_max, w1, v1;
	cin >> n >> w_max;
	cin >> w1 >> v1;
	w[0]++;
	v[0].push_back(v1);
	for (int i = 1; i < n; i++){
		int temp;
		cin >> temp >> v1;
		w[temp-w1]++;
		v[temp-w1].push_back(v1);
	}
	
	for (int i = 0; i < 4; i++){
		sort(v[i].begin(), v[i].end(), greater<int>());
	}

	for (int i = 0; i < 4; i++){
		sum[i].push_back(0);
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < v[i].size(); j++){
			sum[i].push_back(sum[i][j] + v[i][j]);
		}
	}
	ll ans = 0;
	for (int i = 0; i <= w[0]; i++){
		for (int j = 0; j <= w[1]; j++){
			for (int k = 0; k <= w[2]; k++){
				for (int l = 0; l <= w[3]; l++){
					ll tmp = j + 2*k + 3*l + w1*(i+j+k+l);
					if (tmp <= w_max){
						ans = max(ans, sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l]);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
