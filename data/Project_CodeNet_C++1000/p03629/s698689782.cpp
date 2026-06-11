#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> to;
vector<int> memo;

int dfs(int i){
	int &r = memo[i];
	if(r < 0){
		r = INT_MAX;
		for(int j = 0; j < 26; ++j){
			r = min(r, dfs(to[j][i]) + 1);
		}
	}
	return r;
}

int main(){
	string a;
	cin >> a;
	int n = a.size();
	to.assign(26, vector<int>(n + 1, n + 1));
	for(int i = n - 1; i >= 0; --i){
		for(int j = 0; j < 26; ++j){
			to[j][i] = to[j][i + 1];
		}
		to[a[i] - 'a'][i] = i + 1;
	}

	memo.assign(n + 2, -1);
	memo[n + 1] = 0;

	int rest = dfs(0);
	string ans;
	for(int p = 0; rest > 0; --rest){
		int j;
		for(j = 0; memo[to[j][p]] != rest - 1; ++j);
		p = to[j][p];
		ans += char('a' + j);
	}
	cout << ans << '\n';
}
