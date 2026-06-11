#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;
typedef long long LL;
const LL N = 1e9 + 7;

LL n,ans = 1,s;
string a;
string b;
 
int main(){
	cin >> n; cin >> a; cin >> b;
	if(a[0] == b[0]){ ans = 3; s = 1; }
	if(a[0] != b[0]){ ans = 6; s = 2; }
	for(LL i = s;i < n;){
		if(a[i] == b[i] && a[i - 1] == b[i - 1]) ans *= 2;
		if(a[i] == b[i] && a[i - 1] != b[i - 1]) ans *= 1;
		if(a[i] != b[i] && a[i - 1] == b[i - 1]) ans *= 2;
		if(a[i] != b[i] && a[i - 1] != b[i - 1]) ans *= 3;
		if(a[i] != b[i]) i += 2;
		else i ++;
		ans %= N;
	}
	cout << ans << endl;
	return 0;
}