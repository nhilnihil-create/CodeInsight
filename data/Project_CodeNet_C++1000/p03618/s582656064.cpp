#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

char s[N];
int num[100];

int main(){
	scanf("%s", s);
	int n = strlen(s);
	long long ans = 1;
	for (int i = 0; i < n; i++){
		ans += i - num[s[i] - 'a'];
		num[s[i] - 'a']++;
	}
	printf("%lld", ans);
	return 0;
}