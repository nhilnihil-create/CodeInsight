#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL ans,a,b;
int main(){
	cin >> a >> b,ans = a,a -= b;
	while (a && b){
		if (a > b) swap(a,b);
		if (b % a == 0) ans += ((b/a)*2-1) * a,b %= a;
		else ans += (b/a) * a * 2,b %= a;
	}
	cout << ans << '\n';
	return 0;
}