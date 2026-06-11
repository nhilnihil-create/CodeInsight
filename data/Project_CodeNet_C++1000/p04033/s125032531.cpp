#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if(0 < a && a <= b) printf("Positive\n");
	else if(a <= b && b < 0) {
		if((b - a + 1) % 2 == 0) printf("Positive\n");
		else printf("Negative\n");
	}
	else printf("Zero\n");
	return 0;
}