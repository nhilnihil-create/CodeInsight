#include<bits/stdc++.h>
using namespace std;
char st[1000005];
int f[1000005], nxt[1000005], haa[1000005], ha[1000005];
int main() {
	scanf("%s", st + 1);
	int n = strlen(st + 1);
	for(int i = 0; i < 26; i ++) nxt[i] = 1000000;
	f[n + 1] = 1;
	for(int i = n; i >= 1; i --) {
		nxt[st[i] - 'a'] = i;
		for(int j = 0; j < 26; j ++) {
			if(f[i] == 0 || f[i] > f[nxt[j] + 1] + 1) f[i] = f[nxt[j] + 1] + 1, ha[i] = j, haa[i] = nxt[j] + 1;
		}
	}	
	int now = 1;
	while(now <= n) {
		printf("%c", char(ha[now] + 'a'));
		now = haa[now];
	}
	return 0;
}