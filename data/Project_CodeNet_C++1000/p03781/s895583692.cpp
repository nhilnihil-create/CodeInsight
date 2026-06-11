#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
#include<map>
#include<queue>
using namespace std;
int main() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1;; i++) {
		sum += i;
		if (sum >= n) {
			cout << i;
			break;
		}
	}
	return 0;
}
