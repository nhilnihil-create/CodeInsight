#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;
int n, m, num;
int Arr[MAX_N];

bool cmp1 (int a, int b) {
	if (a & 1)
		return true;
	return false;
}

bool cmp2 (int a, int b) {
	if (b & 1)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> Arr[i];
		num += (Arr[i] & 1);
	}

	if (n == 1) {
		cout << "1\n1\n1";
		return 0;
	}
	
	if (m == 1) {
		cout << Arr[0] << "\n2\n";
		cout << Arr[0] - 1 << " " << 1 << "\n";
		return 0;
	}

	if (2 < num) {
		cout << "Impossible\n";
		return 0;
	}

	sort(Arr, Arr + m, cmp1);
	sort(Arr + 1, Arr + m, cmp2);
    
    cout << Arr[0];
	for (int i = 1; i < m; i++)
		cout << " " << Arr[i];
	cout << "\n";

	cout << m - (Arr[0] == 1) << "\n";
	Arr[0]--, Arr[m - 1]++;
	for (int i = 0; i < m; i++)
		if (Arr[i])
			cout << Arr[i] << " ";
	return 0;
}
