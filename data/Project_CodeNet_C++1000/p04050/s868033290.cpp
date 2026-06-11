#include <bits/stdc++.h>
using namespace std;

const int N = 150;

int n, m, a[N];
vector<int> odd, even, ans;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		scanf("%d", a + i);
	if(m == 1) {
		if(n > 1) printf("%d\n2\n1 %d\n", a[1], a[1] - 1);
		else printf("1\n1\n1\n"); 
		return 0;
	} else {
		int cnt_odd = 0;
		for(int i = 1; i <= m; i++) {
			cnt_odd += a[i] & 1;
			if(a[i] & 1) odd.push_back(a[i]);
			else even.push_back(a[i]);
		}
		if(cnt_odd > 2) return 0 * printf("Impossible\n");
		if(!cnt_odd) {
			for(int i = 1; i <= m; i++)
				printf("%d ", a[i]);
			if(a[1] - 1) printf("\n%d\n%d ", m, a[1] - 1);
			else printf("\n%d\n", m - 1);
			for(int i = 2; i < m; i++)
				printf("%d ", a[i]);
			printf("%d\n", a[m] + 1);
			return 0;
		} else if(cnt_odd == 1) {
			printf("%d ", odd[0]);
			for(auto u : even) printf("%d ", u);
			if(odd[0] - 1) printf("\n%d\n%d ", m, odd[0] - 1);
			else printf("\n%d\n", m - 1);
			for(int i = 0; i < (int) even.size() - 1; ++i)
				printf("%d ", even[i]);
			printf("%d\n", (even[even.size() - 1]) + 1);
		} else {
			printf("%d ", odd[0]);
			for(auto u : even) printf("%d ", u);
			printf("%d", odd[1]);
			if(odd[0] - 1) printf("\n%d\n%d ", m, odd[0] - 1);
			else printf("\n%d\n", m - 1);
			for(auto u : even) printf("%d ", u);
			printf("%d\n", odd[1] + 1);
		}
	}
	return 0;
}