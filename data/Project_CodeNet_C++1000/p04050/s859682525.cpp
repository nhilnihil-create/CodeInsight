#include <bits/stdc++.h>

const int kN = 205;

std::list<int> vec;

int main() {
	int n, m, odd_cnt = 0, bk = 0, cnt = 0, x;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		scanf("%d", &x);
		if(x % 2 == 1) {
			if(!odd_cnt) bk = x;
			else if(odd_cnt == 1) vec.push_front(x);
			++odd_cnt;
		} else vec.push_back(x);
	}
	if(m == 1 && x <= 2) { printf("%d\n1\n%d\n", x, x); return 0; } 
	if(m == 1) { printf("%d\n2\n%d %d", x, x - 1, 1); return 0; }
	if(odd_cnt > 2) { printf("Impossible"); return 0; }
	if(bk) vec.push_back(bk);
	for(int i : vec) printf("%d ", i);
	--vec.front(); ++vec.back();
	for(int i : vec) if(i) ++cnt;
	printf("\n%d\n", cnt);
	for(int i : vec) if(i) printf("%d ", i);
	return 0;
}