#include <cstdio>
using namespace std;
const int NL = 105;
int N;
char s[NL], t[NL];
int main() {
	scanf("%d%s%s", &N, s + 1, t + 1);
	for (int i = 1; i <= N+1; ++i) {
		bool match = 1;
		for (int j = i; j <= N; ++j)
			if (s[j] != t[j - i + 1]) {
				match = 0;
				break ;
			}
		if (match) {
			printf("%d\n", 2 * N - (N + 1 - i));
			break ;
		}
	}
	return 0;
}