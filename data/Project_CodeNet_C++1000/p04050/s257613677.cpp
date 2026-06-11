#include <bits/stdc++.h>

using namespace std;

#define K 501
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define pb push_back

int n, m;

int oc = 0;
int a[K];

vector<int> sol;

void solveE() {
	if (oc > 2) {
		puts("Impossible");
		return;
	}
	
	if (oc == 0) {
		sol.pb(1);
	
		FOE(i, 1, m) printf("%d%c", a[i], (i == m ? '\n': ' '));
		FOE(i, 1, m) {
			if (i != m) sol.pb(a[i]);
			else if (a[i] >= 2) sol.pb(a[i] - 1);	
		}
		printf("%d\n", sol.size());
		
		for (int i = 1; i <= sol.size(); i++) {
			printf("%d%c", sol[i - 1], (i == sol.size() ? '\n': ' '));	
		}
	} else {
		int good1 = -1, good2 = -1;
		
		FOE(i, 1, m) {
			if (a[i] % 2 == 1) {
				if (good1 == -1) good1 = i;
				else good2 = i;
			}
		}
		
		int t = a[1]; a[1] = a[good1]; a[good1] = t;
		t = a[m]; a[m] = a[good2]; a[good2] = t;
	
		FOE(i, 1, m) printf("%d%c", a[i], (i == m ? '\n': ' '));
	
		FOE(i, 1, m) {
			if (i == 1) {
				if (a[1] > 1) sol.pb(a[1] - 1);
			} else if (i == m) {
				sol.pb(a[m] + 1);	
			} else {
				sol.pb(a[i]);	
			}
		}
		printf("%d\n", sol.size());
		
		for (int i = 1; i <= sol.size(); i++) {
			printf("%d%c", sol[i - 1], (i == sol.size() ? '\n': ' '));	
		}
	}
}

void solveO() {
	if (oc > 1) {
		puts("Impossible");
		return;
	}	
	
	if (n == 1) {
		puts("1\n1\n1\n");
		return;	
	}
	
	int good = 0;
	
	FOE(i, 1, m) if (a[i] % 2) good = i;
	
	int t = a[m]; a[m] = a[good]; a[good] = t;
	
	FOE(i, 1, m) printf("%d%c", a[i], (i == m ? '\n': ' '));
	
	int items = m + (a[m] != 1);
	
	printf("%d\n", items);
	
	int left = n;
	
	FOE(i, 1, items) {
		if (i == 1) {
			printf("%d", 1);
			left--;	
		} else if (i != items) {
			printf("%d", a[i - 1]);
			left -= (a[i - 1]);
		} else {
			printf("%d", left);	
		}
		
		if (i != items) printf(" ");
		else puts("");
	}
}

int main() {
	scanf("%d%d", &n, &m);
	
	FOE(i, 1, m) {
		scanf("%d", &a[i]);
		
		if (a[i] % 2) oc++;
	}
	
	if (n % 2 == 0) {
		solveE();
	} else {
		solveO();	
	}
}