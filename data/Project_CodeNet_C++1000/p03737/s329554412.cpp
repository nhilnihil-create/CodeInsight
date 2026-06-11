// ABC059A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	printf("%c%c%c\n", s1[0] - ('a' - 'A'), s2[0] - ('a' - 'A'), s3[0] - ('a' - 'A'));

	return 0;
}
