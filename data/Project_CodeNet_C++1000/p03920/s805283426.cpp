#include<iostream>
#include<vector>
using namespace std;

int n, sum;
vector<int>v;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += i;
		v.push_back(i);
		if (sum >= n)break;
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == sum - n && n != 1)continue;
		cout << v[i] << endl;
	}
}