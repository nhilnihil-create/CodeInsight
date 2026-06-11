#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 100005;

LL s[N << 1],vis[N << 1];

int main(){
	LL n,x,now = 1;
	cin >> n >> x;
	if(x == 1 || x == (n << 1) - 1){ cout << "No\n"; return 0; }
	if(x == 2){
		s[n] = x; s[n - 1] = 1; s[n - 2] = (n << 1) - 2; s[n + 1] = (n << 1) - 1;
		now = 2;
		for(LL i = 1;i <= (n << 1) - 1;i ++){
			if(s[i]) continue;
			if(now == x) now ++;
			s[i] = now; now ++;
		}
	}
	else{
		s[n] = x; s[n - 1] = (n << 1) - 1; s[n - 2] = 1; s[n + 1] = 2;
		now = 3;
		for(LL i = 1;i <= (n << 1) - 1;i ++){
			if(s[i]) continue;
			if(now == x) now ++;
			s[i] = now; now ++;
		}
	}
	cout << "Yes\n";
	for(LL i = 1;i <= (n << 1) - 1;i ++) cout << s[i] << '\n';
	return 0;
}