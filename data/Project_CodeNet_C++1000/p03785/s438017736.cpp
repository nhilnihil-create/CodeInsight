#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main() {

	long long n, c, k;
	cin >> n >> c >> k;

	vector<long long> T;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		T.push_back(tmp);
	}

	sort(T.begin(), T.end());
	queue<int> q;
	for (int i = 0; i < n; i++) {
		q.push(T[i]);
	}
	
	int ans = 0;

	while (q.size()) {
		int x = q.front() + k;
		ans++;
		int count = 0;
		while (q.size() && count < c && q.front() <= x) {
			q.pop();
			count++;
		}
	}
	
	cout << ans << endl;


	return 0;
}