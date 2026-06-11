#include <cstdio>
#include <cstring>

char str[100];

int main() {
	scanf("%s", str);
	if (strncmp(str, "YAKI", 4) == 0)
		puts("Yes");
	else puts("No");
	return 0;
}
