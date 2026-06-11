#include<cstdio>
#include<algorithm>
#include<map> 
using namespace std;

typedef long long ll;

const int MAXN = 100010;

int a[MAXN];

map<int, bool> mp;

int main(){
	int N, ans = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= N; i += 2)
		mp[a[i]] = 1;
	for (int i = 2; i <= N; i += 2)
		mp[a[i]] = 0;
	sort(a + 1, a + 1 + N);
	for (int i = 1; i <= N; ++i)
		if ((i & 1) != mp[a[i]])
			++ans;
	printf("%d", ans >> 1);
	return 0;
}