#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	int dx, dy;
	dx = min(n, k);
	dy = max(0, n - k);
	cout << dx * x + dy * y<<endl;
}