#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,x;
	cin >> n >> x;
	//まず,最小値と最大値は選ばれない.
	if(x == 1 || x == 2 * n - 1){
		cout << "No" << endl;
		return 0;
	}

	//それ以外なら,連続して2つ選ばれる構築をすることでずっと上に持ち上げられる.

	vector<int> ans(2 * n - 1, 0);
	vector<bool> used(2 * n);

	ans[(2 * n - 2) / 2] = x, used[x] = true;
	ans[(2 * n - 2) / 2 + 1] = x + 1, used[x + 1] = true;
	ans[(2 * n - 2) / 2 - 1] = x - 1, used[x - 1] = true;

	if(x + 2 <= n){
		ans[(2 * n - 2) / 2 - 2] = x + 2, used[x + 2] = true;
	}
	else if(x - 2 >= 1){
		ans[(2 * n - 2) / 2 + 2] = x - 2, used[x - 2] = true;
	}

	int now = 1;
	for(int i = 0;i < 2 * n - 1;i++){
		if(ans[i] == 0){
			while(used[now])now++;
			ans[i] = now;
			used[now] = true;
		}
	}

	cout << "Yes" << endl;
	for(int i = 0;i < 2 * n - 1;i++){
		cout << ans[i] << endl;
	}
}
