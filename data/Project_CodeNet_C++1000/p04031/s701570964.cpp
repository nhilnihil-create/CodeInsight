#include <iostream>
#include <stdio.h>
using namespace std;
int ar[200], n;
long long findTotal(int val) {
	long long int ans = 0;

	for(int i = 0; i < n; i++){
	   // cout << ar[i] << " *\n";
		ans += (val - ar[i]) * (val - ar[i]);
	}
    // cout << ans << " ^ " << val << endl;
	return ans;
}

int main() {
    
	cin >> n;
	
	int lo = 1e9, hi = -1;
	
	for(int i = 0; i < n; i++) {
		cin >> ar[i];

		lo = ar[i] < lo ? ar[i] : lo;
		hi = ar[i] > hi ? ar[i] : hi;
	}
    
    long long ans = (int)1e9;
    
    for(int i = lo ; i <= hi; i++) {
        long long sol = findTotal(i);
        ans = ans > sol ? sol : ans;
    }

	
	printf("%lld\n", ans == (int) 1e9 ? 0 : ans);
}