#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n; n = 2 * n - 1;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int lo = 1, hi = n, ans = 1;
	while(lo <= hi){
		int mid = (lo + hi)>>1;
		vector<int> b = a;
		for(int i = 0; i < n; i++) b[i] = b[i] >= mid;
		int i = n / 2, j = i;
		int found = -1;
		while(i > 0){
			if(b[i] == b[i - 1] || b[j] == b[j + 1]){
				found = b[i];
				break;
			}
			i--;
			j++;
		}	
		if(found == -1){
			if((n / 2 + 1) % 2) found = b[n / 2];
			else found = 1 ^ b[n / 2];
		}
		if(found) ans = mid, lo = mid + 1;
		else hi = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
