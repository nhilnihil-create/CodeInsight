#include <bits/stdc++.h>
using namespace std;

struct Node{
	int pos, val;
};

int a[250010];
Node w[505];

bool cmp(const Node& x, const Node& y){
	return x.pos < y.pos;
}

int main(){
	int n, p, cnt;
	scanf("%d",&n);
	memset(a, 0, sizeof(a)); 
	for (int i = 1; i <= n; i++){
		scanf("%d",&w[i].pos);
		w[i].val = i;
		a[w[i].pos] = i;
	}
	sort(w + 1, w + n + 1, cmp);
	p = 1;
	for (int i = 1; i <= n; i++){
		cnt = 0;
		while (p < w[i].pos && cnt < w[i].val - 1){
			if (!a[p]){
				a[p] = w[i].val;
				cnt++;
			}
			p++;
		}
		if (cnt < w[i].val - 1){
			printf("No\n");
			return 0;
		}
	}
	p = n * n;
	for (int i = n; i >= 1; i--){
		cnt = 0;
		while (p > w[i].pos && cnt < n - w[i].val){
			if (!a[p]){
				a[p] = w[i].val;
				cnt++;
			}
			p--;
		}
		if (cnt < n - w[i].val){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 1; i <= n * n; i++){
		printf("%d", a[i]);
		if (i < n * n) printf(" ");
		else printf("\n");
	}
	return 0;
}