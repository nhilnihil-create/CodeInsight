#include <cstdio>
#include <cstring>
int Len;
char s[ 100005 ];
int main() {
	scanf ("%s", s);
	Len = strlen(s);
	printf ("%s\n", ((Len % 2 == 1) ^ (s[ 0 ] == s[ Len - 1 ])) ? "First" : "Second");
	return 0;
}