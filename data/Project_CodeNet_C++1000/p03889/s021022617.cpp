#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib> 
using namespace std;
int a[100010], b[100010];
int main() {
	int top = 0;
	char ch = getchar();
	while (!isalpha(ch)) ch = getchar();
	while (isalpha(ch)) {
		if (ch == 'b') a[++top] = 0;
		if (ch == 'd') a[++top] = 1;
		if (ch == 'p') a[++top] = 2;
		if (ch == 'q') a[++top] = 3;
		ch = getchar();
	}
	for (int i = 1; i <= top; ++i)
		b[i] = a[top - i + 1] ^ 1;
	for (int i = 1; i <= top; ++i)
		if (a[i] != b[i]) 
			puts("No"), exit(0);
	puts("Yes");
	return 0;
}
