#include <iostream>
#define int long long
#define MOD 1000000007
using namespace std;

signed main(){
	int n,d[100000],last = -1,pos = 0,ans = 1;
	cin >> n;
	for(int i = 0;i < n;i++){
		int x;
		cin >> x;
		x = min(last + 2,x);
		d[i] = x - last;
		last = x;
	}
	for(int i = 0;i < n;i++){
		while(d[pos] == 2 && pos < n - 1) pos++;
		(ans *= pos - i + 1) %= MOD;
		d[pos] = 2;
		while(d[pos] == 2 && pos < n - 1) pos++;
		d[pos] = 2;
	}
	cout << ans << endl;
	return 0;
}