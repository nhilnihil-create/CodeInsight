#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 1; i <= b; i++) {
		if (i * a % b == c)
			return printf("YES\n"), 0;
	}
	printf("NO\n");
}
