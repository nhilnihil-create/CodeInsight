#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
#define N 200010

int f[N];
int pos[N][26];
char s[N];

int main() {
	memset(f, 0x3f, sizeof(f));
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 0; i < 26; ++i) pos[n + 1][i] = n + 1;
	f[n + 1] = 1, f[n + 2] = 0;
	for(int i = n; i; i--) {
		for(int j = 0; j < 26; ++j) 
			pos[i][j] = pos[i + 1][j];
		pos[i][s[i] - 'a'] = i;
	}
	for(int i = n; i; i--) 
		for(int j = 0; j < 26; ++j)
			f[i] = min(f[i], f[pos[i][j] + 1] + 1);
	int now = 1;
	for(int j = f[1]; j; --j)
		for(int i = 0; i < 26; ++i) 
			if(f[now] == f[pos[now][i] + 1] + 1) {
				putchar(i + 'a');
				now = pos[now][i] + 1;
				break;
			}
}
