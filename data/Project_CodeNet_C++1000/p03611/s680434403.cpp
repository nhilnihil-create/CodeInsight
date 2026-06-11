#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(100005);

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != 0) {
			a[x - 1]++;
		}
		a[x]++;
		a[x + 1]++;
	}
	
	sort(a.begin(), a.end(), greater<int>());

	cout << a[0] << endl;

	return 0;
}