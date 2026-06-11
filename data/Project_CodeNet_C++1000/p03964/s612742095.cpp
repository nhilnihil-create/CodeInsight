#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	
 	cin >> n;
 	long long t, a, taka = 1, ao = 1;

 	while (n--) {
 		cin >> t >> a;
 		long long m = max(taka / t + (taka % t != 0), ao / a + (ao % a != 0));
 		taka = t * m;
 		ao = a * m;
 	}
 	cout << taka + ao << '\n';
 	
	return 0;
}