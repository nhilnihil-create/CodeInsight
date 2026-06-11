#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[305][305];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i >= j) continue;
			bool flag = true;
			for(int k = 1; k <= n; k++){
				if(i == k || j == k) continue;
				if(a[i][k] + a[k][j] < a[i][j]){
					cout << -1 << endl;
					return 0;
				}
				if(a[i][k] + a[k][j] == a[i][j]) flag = false;
			}
			if(flag) ans += a[i][j];
		}
	}
	cout << ans << endl;
	
	return 0;
}