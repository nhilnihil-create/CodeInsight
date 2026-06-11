#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include <bitset>
#include<set>
#include<map>
#include<vector>
#include<cmath>
#include<string>
typedef long long ll;
using namespace std;

int arr[200];
int main() {
	int n;
	int res = 0;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 2 * n);
	for (int i = 0; i < 2 * n; i = i + 2) {
		res += arr[i];
	}
	cout << res << endl;
	return 0;
}
