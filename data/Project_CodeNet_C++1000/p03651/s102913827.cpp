#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int gcd(int a, int b) {
   if (a % b == 0) {
       return(b);
   } else {
       return(gcd(b, a % b));
   }
}

int main() {
	int N, K;
	cin >> N >> K;

	int a0;
	cin >> a0;
	int val = a0;
	int MAX = val;
	for (int ii = 1; ii < N; ++ii){
		int a;
		cin >> a;
		MAX = max(MAX, a);
		val = gcd(val, a);
	}

	if ((K % val == 0) && (K <= MAX)){
		cout << "POSSIBLE" << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;		
	}


	return 0;
}
