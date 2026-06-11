#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

int a[100005];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == i+1)a[i] = 1;
		else a[i] = 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			if (a[i + 1] == 1) {
				a[i] = a[i + 1] = 0;
				ans++;
			}
			else {
				a[i] = 0;
				ans++;
			}
		}
	}
	cout << ans;
}