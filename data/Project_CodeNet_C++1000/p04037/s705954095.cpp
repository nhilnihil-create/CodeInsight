#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
int n, ind;
int Arr[MAX_N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> Arr[i];

	if (n == 1) {
		if (Arr[0] % 2 == 1)
			cout << "Second\n";
		else
			cout << "First\n"; 
			
		return 0;
	}
	
	sort(Arr, Arr + n);
	reverse(Arr, Arr + n);
	
	if (Arr[0] == 1) {
		if (n % 2 == 1)
			cout << "Second\n";
		else
			cout << "First\n"; 
			
		return 0;
	}
	
	ind = n;
	int h = Arr[0];
	for (int i = 1; i < n; i++) {
		if (Arr[i - 1] >= i && Arr[i] <= i) {
			ind = i;
			break;
		}
	}
	
	ind--;
		
//	cout << ind << "\n";

	if ((Arr[ind] - ind) % 2 == 0) {
		cout << "First\n";
		return 0;
	}
	
	int cnt = 0;
	int tmp = ind + 1;
	while (tmp < n && Arr[tmp] == ind + 1) {
		tmp++;
		cnt++;
	}
	
	if (cnt % 2 == 1) {
		cout << "First\n";
		return 0;
	}
	
	cout << "Second\n";
	return 0;
}
