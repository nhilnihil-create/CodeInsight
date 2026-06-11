#include<cstdio>
#include<bitset>
using namespace std;

const int MAXN = 200010;

int N, len, a[MAXN];
bool le[MAXN];//bitset<MAXN> le;

bool check(int lim){
	for (int i = 1; i <= len; ++i)
		if (a[i] <= lim)
			le[i] = 1;
		else
			le[i] = 0;
	bool s = le[N];
	for (int j = 1; j < N; ++j)
		if (le[N - j] == le[N + j] && le[N + j] == (s ^ (j & 1)))
			continue;
		else 
			return (s ^ (j & 1)) ^ 1;
	return le[N] ^ (N & 1) ^ 1;
}

int main(){
	scanf("%d", &N);
	len = N * 2 - 1;
	for (int i = 1;  i <= len; ++i)	
		scanf("%d", &a[i]);
	int l = 1, r = len, mid;
	while (l + 1 < r){
		mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	if (check(l))
		printf("%d", l);
	else
		printf("%d", r);
	return 0;
}
