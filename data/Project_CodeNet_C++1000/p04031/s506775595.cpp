#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);

	for (int i=0; i<n; i++)
		cin >> vec[i];

	sort (vec.begin(), vec.end());

	//int diff = vec[vec.size()-1] - vec[0];
	if (vec[0] == vec[vec.size()-1]) {
		cout << "0";
	}
	else {
		int res = INT_MAX;
		int counter = 0;
		int temp = vec[0];
		while (temp <= vec[vec.size()-1]) {
			int sum = 0;
			for (int i=0; i<vec.size(); i++) {
				sum += (temp - vec[i])*(temp-vec[i]);
			}
			res = min (res, sum);
			temp++;
		}
		cout << res;
	}
}