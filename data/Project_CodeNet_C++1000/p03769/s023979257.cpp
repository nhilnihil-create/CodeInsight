#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;

typedef long long LL;

int cnt;
LL n;

deque <int> Q;

void Build(LL N)
{
	if (N == 1) return;
	if (N & 1)
	{
		Build(N - 1);
		Q.push_front(++cnt);
	}
	else
	{
		Build(N >> 1LL);
		Q.push_back(++cnt);
	}
}

int main()
{
	#ifdef DMC
		freopen("DMC.txt","r",stdin);
	#endif
	
	cin >> n; Build(n + 1); cout << (cnt << 1) << endl;
	while (!Q.empty()) printf("%d ",Q.front()),Q.pop_front();
	for (int i = 1; i < cnt; i++) printf("%d ",i); cout << cnt << endl;
	return 0;
}