#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int k, n;
	int max=0;
	vector<int> l(50);
	cin >> n>>k;
	for (int i = 0; i <n; i++) {
		cin >> l[i];
	}
	sort(l.begin(), l.end(), greater<int>());
	for (int i = 0; i < k; i++) {
		max += l[i];
	}
	cout << max;
}