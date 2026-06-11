#include<iostream>
#include<vector>
using namespace std;
int max(vector < vector<unsigned int>> ab, unsigned int  n) {
	unsigned int max = ab.at(0).at(0);

	for (unsigned int i = 1; i < n; i++) {
		if (max <= ab.at(0).at(i)) {
			max = ab.at(0).at(i);
		}
	}
	return max;
}

int main() {
	unsigned int n;
	cin >> n;
	vector<vector<unsigned int>>ab(2, vector<unsigned int>(n));
	for (unsigned int i = 0; i < n; i++) {
		cin >> ab.at(0).at(i) >> ab.at(1).at(i);
	}
	unsigned int k=0;
	unsigned int m = max(ab, n);
	for (unsigned int i = 0; i < n; i++) {
		if (ab.at(0).at(i) == m)k = i;
	}
		cout << m + ab.at(1).at(k) << endl;
	
}
