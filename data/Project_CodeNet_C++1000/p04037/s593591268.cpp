#include<bits/stdc++.h>
const int maxn = 200200;
const int mod = 1e9 + 7;
const int N = 2010;
typedef long long ll;
int n;
int a[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for(int i = 1;i <= n;++i) std::cin >> a[i];
	std::sort(a + 1, a + n + 1, std::greater<int>());
	for(int i = 1;i <= n;++i) 
		if(i + 1 > a[i + 1]) {
			if((std::count(a + i + 1, a + n + 1, i) | a[i] - i) & 1) {
				puts("First");
			} else {
				puts("Second");
			}
			return 0;
		}
}
