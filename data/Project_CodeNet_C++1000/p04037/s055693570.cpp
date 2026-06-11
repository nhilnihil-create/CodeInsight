#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int> a;
int main() {
	scanf("%d", &n);
	a.resize(n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a.rbegin(), a.rend());

	int cur = 0;
	while(cur < n && cur < a[cur]) cur++;
	cur--;

	int j = cur + 1;
	while(j < n && a[j] > cur) j++;
	if(((j - cur - 1) % 2 == 1) || ((a[cur] - cur - 1) % 2 == 1)) printf("First\n");
	else printf("Second\n");
	return 0;
}