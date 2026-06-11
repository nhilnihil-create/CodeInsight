#include "bits/stdc++.h"
using namespace std;
int N;
vector<int>to[100005];

int main() {
	int N;
	cin >> N;
	map<int, int>mp;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		mp[n]++;
	}
	int count = 0;
	int count2 = 0;
	for (auto p:mp) {
		int n = p.second;
		if (1 == n%2) {
			count++;
		}
		else {
			count2++;
		}
	}
	if (1 == count2%2) {
		count += count2 - 1;
		count2 = 1;
	}
	else {
		count += count2 - 2;
		count2 = 2;
	}
	if (1 == count2) {
	}
	else {
		count += 2;
	}
	cout << count << endl;
	return 0;
}