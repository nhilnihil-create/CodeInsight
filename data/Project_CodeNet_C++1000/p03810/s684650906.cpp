#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5 + 10;

int n;
int a[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	bool flag = false;
	while (true){
		auto odd = [](int t){return t & 1;};
		int cnt = count_if(a, a + n, odd), t = find_if(a, a + n, odd) - a;
		if (cnt > 1 || a[t] == 1 || accumulate(a, a + n, 0ll) - n & 1)
			break;
		flag ^= 1;
		--a[t];
		transform(a, a + n, a, bind2nd(divides<int>(), accumulate(a, a + n, 0, __gcd<int>)));
	}
	flag ^= accumulate(a, a + n, 0ll) - n & 1;
	puts(flag ? "First" : "Second");
	return 0;
}
