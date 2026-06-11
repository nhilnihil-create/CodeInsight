#include <bits/stdc++.h>
using namespace std;

signed main(){
	string  s1, s2, s3;
	char d = 'A' - 'a';
	cin >> s1 >> s2 >> s3;
	printf("%c%c%c\n", s1[0] + d, s2[0] + d, s3[0] + d);
	return 0;
}