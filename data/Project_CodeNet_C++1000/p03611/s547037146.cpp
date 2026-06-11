#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++){
        cin >> a[i];
	}
	map <int, int> cnt;
	for (int i = 0; i < n; i++){
        cnt[a[i]]++;
        cnt[a[i] - 1]++;
        cnt[a[i] + 1]++;
	}
	int ans = 0;
	for (auto x : cnt){
	ans = max(ans, x.second);
	}
	cout << ans << endl;
	return 0;
}
