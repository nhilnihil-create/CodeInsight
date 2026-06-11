#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(2, vector<int>(n)); 
	for (int i = 0; i < n; i++) {
		cin >> a.at(0).at(i) >> a.at(1).at(i);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a.at(1).at(i) - a.at(0).at(i) + 1;
	}
	cout << sum;
}