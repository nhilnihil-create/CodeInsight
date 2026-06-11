#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	int i = 1, sum = 0;
	while (sum + i < n) {
		sum += i;
		i++;
	}
	
	cout << i;
}