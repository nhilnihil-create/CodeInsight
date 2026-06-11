#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

namespace IO {
    inline LL read() {
        LL o = 0, f = 1; char c = getchar();
        while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
        while (c > '/' && c < ':') { o = o * 10 + c - '0'; c = getchar(); }
        return o * f;
    }
    inline char recd() {
        char o; while ((o = getchar()) != '1' && o != '0'); return o;
    }
}
using namespace IO;

char Map[233];

int main() {
	Map['b'] = 'd';
	Map['d'] = 'b';
	Map['p'] = 'q';
	Map['q'] = 'p';

	string str; cin >> str;
	for (int pos = 0; pos <= str.size() / 2; pos++)
		if (Map[str[pos]] != str[str.size() - 1 - pos]) {
			puts("No"); return 0;
		}
	puts("Yes");
}
