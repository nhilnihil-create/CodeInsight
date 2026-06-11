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


int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	ll tmp = 0, ans1 = 0;
	for (int i = 0; i < n; i++){
		tmp += a[i];
		if (i%2 == 0){
			if (tmp >= 0){
				ans1 += tmp + 1;
				tmp = -1;
			}
		}else{
			if (tmp <= 0){
				ans1 += -tmp + 1;
				tmp = 1;
			}
		}
	}
	tmp = 0;
	ll ans2 = 0;
	for (int i = 0; i < n; i++){
		tmp += a[i];
		if (i%2 == 0){
			if (tmp <= 0){
				ans2 += -tmp + 1;
				tmp = 1;
			}
		}else{
			if (tmp >= 0){
				ans2 += tmp + 1;
				tmp = -1;
			}
		}
	}
	cout << min(ans1, ans2) << endl;
	return 0;
}

