#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

int main() {
	int N, a, ans=1;
	queue<int> alist;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		alist.push(a);
	}

	while (!alist.empty()) {
		int lastA = alist.front(), newA, flag=0;
		alist.pop();
		while (!alist.empty()) {
			newA = alist.front();
			alist.pop();
			if (newA != lastA && flag == 0) {
				flag = (newA - lastA > 0) ? 1 : -1;
			}
			else if (newA - lastA < 0 && flag == 1) {
				ans++;
				flag = 0;

			}
			else if (newA - lastA > 0 && flag == -1) {
				ans++;
				flag = 0;
			}
			lastA = newA;
		}
	}
	print(ans);
}