#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
// head
const int maxn = 2e5 + 5;
int s[maxn], top, n;
char ch[maxn];

int main() {
	cin>>ch;
	n = strlen(ch);
	rep(i, 0, n - 1) {
		if(ch[i] == 'S') s[++top] = 0;
		else {
			if(s[top] == 0 && top) top--;
			else s[++top] = 1;
		}
	}
	cout<<top<<endl;
}