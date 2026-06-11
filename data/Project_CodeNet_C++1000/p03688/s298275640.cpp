#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define LL long long
#define pb push_back
#define mp make_pair
#define M 1000000007
#define y1 fwfwkpoe
 
#define K 200001

int n;
int a[K];

int main() {
	scanf("%d", &n);
	
	FOE(i, 1, n) scanf("%d", &a[i]);
	
	sort(a + 1, a + n + 1);
	
	if (a[n] - a[1] >= 2) {
		puts("No"); return 0;	
	}
	
	if (a[n] == a[1]) {
		if (a[n] == n - 1) {
			puts("Yes"); return 0;	
		}
		
		int maxpairs = n / 2;
		
		if (a[n] <= maxpairs) {
			puts("Yes"); return 0;	
		}
		
		puts("No"); return 0;
	}
	
	int low = 0, high = 0;
	
	FOE(i, 1, n) {
		if (a[i] == a[1]) low++;
		if (a[i] == a[n]) high++;	
	}
	
	int maxpairs = high / 2;
	
	if (high == 1) {
		puts("No"); return 0;	
	}
	
	if (a[n] > low + maxpairs) {
		puts("No"); return 0;	
	}
	
	if (a[1] == 1 && low >= 2) {
		puts("No"); return 0;	
	}
	
	puts("Yes"); return 0;
}
