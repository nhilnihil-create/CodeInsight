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
const ll LLINF = 1e18;
using namespace std;

int road[201][201];

int main(){
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> machi(r);
	for (int i = 0; i < r; i++){
		cin >> machi[i];
	}
	for (int i = 0; i <= 200; i++){
		for (int j = 0; j <= 200; j++){
			road[i][j] = MOD;
		}
	}
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		road[a][b] = c;
		road[b][a] = c;
	}
	for (int k = 1; k <= n; k++){
    	for (int i = 1; i <= n; i++) {
      		for (int j = 1; j <= n; j++) {
        		road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
      		}
    	}
  	}
	sort(machi.begin(), machi.end());
	int ans = MOD;
	do {
		int tmpans = 0;
    	for (int i = 0; i < r-1; i++){
    		tmpans += road[machi[i]][machi[i+1]];
    	}
    	ans = min(ans, tmpans);
  	} while (next_permutation(machi.begin(), machi.end()));
  	cout << ans << endl;
	return 0;
}