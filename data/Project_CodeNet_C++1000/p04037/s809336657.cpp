//atcoder 002 E Candy Piles 博弈论 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);//逆转元素，从大到小
	bool flag = 0; 
	for (int i = 1; i <= n; i++) 
	if (i+1 > a[i+1]) {
		for (int j = i+1; a[j] == i; j++) flag ^= 1;
		flag |= (a[i]-i) & 1;
		if (flag) printf("First\n");else printf("Second\n");
		return 0;
	} 
}