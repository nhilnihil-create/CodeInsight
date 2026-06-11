#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)

int a, b;
int main() {
	scanf("%d %d", &a, &b);
	if (a <= 0 && b >= 0) puts("Zero");
	else if (b < 0 && (b-a+1)%2) puts("Negative");
	else puts("Positive");



	return 0;
}
