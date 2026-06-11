#include <bits/stdc++.h>

using namespace std;

#define K 500001
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define pb push_back

int n;
int a[K];

int main() {
	scanf("%d", &n);
	
	FOE(i, 1, n) {
		scanf("%d", &a[i]); a[i] *= -1;
	}

	sort(a + 1, a + n + 1);
	
	FOE(i, 1, n) a[i] *= -1;
	
	int good = -1;
	
	FOE(i, 1, n) {
		if (a[i] >= i) good = i;
	}
	
//	printf("good is %d\n", good);
	
	int sol = 2;
	
	int dist = a[good] - good;
	
	if (dist % 2) sol = 1;
		
	int id = good;
	
	while (id < n && a[id + 1] >= good) id++;
	
	dist = id - good;
	
	if (dist % 2) sol = 1;
	
	if (sol == 2) puts("Second"); else puts("First");
}