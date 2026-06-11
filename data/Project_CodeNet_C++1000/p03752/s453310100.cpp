#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	ll real_ans = 1e18;
	for (int i = 0; i < (1<<(n-1)); i++){
		vector<bool> tower(n-1);
		int coun = 0; 
		for (int j = 0; j < n-1; j++){
			if (i & (1<<j)){
				tower[j] = true;
				coun++;
			}else{
				tower[j] = false;
			}
		}
		if (coun < k-1) continue;
		ll ans = 0;
		int tmp_max = a[0];
		for (int j = 0; j < n-1; j++){
			if (tower[j] == false){
				tmp_max = max(a[j+1], tmp_max);
			}else{
				ans += max(tmp_max - a[j+1] + 1, 0);
				tmp_max = max(tmp_max + 1, a[j+1]);
			}
		}
		real_ans = min(ans, real_ans);
	}
	cout << real_ans << endl;
	return 0;
}