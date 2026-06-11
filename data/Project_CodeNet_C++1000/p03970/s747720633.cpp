#include <cstdio>
#include <cstring>

using namespace std;

int main () {
	char s[16] = {'C', 'O', 'D', 'E', 'F', 'E', 'S', 'T', 'I', 'V', 'A', 'L', '2', '0', '1', '6'}, a[16];
	scanf("%s", &a);
	int cnt = 0;
	for (int i = 0; i < 16; i++) {
		if (s[i] != a[i])
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}