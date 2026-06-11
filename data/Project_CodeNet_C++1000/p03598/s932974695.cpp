#include<iostream>
#include <vector>
using namespace std;
int ab(int k, vector<int> x,int n) {
	return (x.at(n) < (k > x.at(n) ? k - x.at(n) : x.at(n) - k)) ? x.at(n) : (k > x.at(n) ? k - x.at(n) : x.at(n) - k);
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<int>x(n);
	for (int i = 0; i < n; i++) {
		cin >> x.at(i);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += ab(k, x, i)*2;
	}
	cout<<sum;
	return 0;
}