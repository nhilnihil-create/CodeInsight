#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[100010], s[100010], as[100010], ans;

int main(){
	scanf("%d%lld", &n, a + 1);
	s[1] = as[1] = a[1];
	for(int i = 2; i <= n; i++){
		char buf[3]; scanf("%s%d", buf, a + i);
		as[i] = as[i - 1] + a[i];
		if(buf[0] == '-') a[i] *= -1;
		s[i] = s[i - 1] + a[i];
	}
	ans = s[n];
	for(int i = 2; i <= n; i++){
		if(a[i] < 0){
			ll ts = 2 * a[i];
			for(int j = i + 1; j <= n; j++){
				if(a[j] < 0) break;
				ts -= 2 * a[j];
			}
			ans = max(ans, ts + s[i - 1] + as[n] - as[i - 1]);
		}
	}
	printf("%lld\n", ans);
}