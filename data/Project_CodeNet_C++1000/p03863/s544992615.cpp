//#pragma GCC optimize(3)
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
typedef long long LL;
using namespace std;
#define MAXN 500005
#define eps (1e-11)
#define lyh 19260817
#define njj 19491001
const double pi = acos(-1.0);
#define P pair<int,int>
//#define int LL

char s[MAXN];

signed main() {
	scanf("%s", s);
	int len = strlen(s);
	if (s[0] == s[len - 1]) len++;
	if (len % 2) printf("First");
	else printf("Second");
	return 0;
}