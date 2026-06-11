#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int freq[128];
int len;
char str[200005];
long long ans;

int main(){
	scanf("%s", str);
	len = strlen(str);
	ans = 1;
	for(int i = 0; i < len; i++){
		ans += i - freq[str[i]];
		freq[str[i]]++;
	}
	printf("%lld\n", ans);
	return 0;
}