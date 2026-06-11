#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a[100000],sum = 0;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a,a + n);
	int l = 0,r = n - 1;
	for(int i = n - 1;i >= 1;i--) a[i] -= a[i - 1];
	while(1){
		int nl = l,nr = r - 1;
		a[l]--;
		while(!a[nl] && nl <= nr) nl++;
		if(nl > nr){
			a[l]++;
			break;
		}
		l = nl;
		r = nr;
	}
	for(int i = l;i <= r;i++) sum += a[i];
	if((l + 1 <= r && (r - l) % 2) || sum % 2 == 0) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}