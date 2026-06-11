//Created Time:2019年12月18日 星期三 18时32分15秒
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long n;
int a[2002];
int cnt;

int main(){
	cin >> n; ++n;
	int l = 0, r = 50; bool flag = false;
	for(int i = 39, pos = 1; ~i; --i){
		long long p = 1ll << i;
		if(p > n) continue;
		if(p & n){
			if(flag)
				++cnt, a[++l] = pos++;
			else flag = true;
		}
		if(i) a[++r] = pos++, ++cnt;
	}
	cout << cnt + 100 << endl;
	for(int i = l; i; --i) cout << a[i] << ' ';
	for(int i = 51; i <= r; ++i) cout << a[i] << ' ';
	for(int i = 1; i <= 100; ++i) cout << i << ' ';
	return 0;
}
