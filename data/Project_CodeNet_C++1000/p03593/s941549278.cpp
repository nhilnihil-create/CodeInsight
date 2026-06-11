#include <iostream>
#include <cstdio>
#define N 105
using namespace std;

int h, w, c[150], na[4];
string a;
int main()
{
	int i, j;
	cin >> h >> w;
	for (i = 0; i < h; i++) {
		cin >> a;
		for (j = 0; j < w; j++) c[a[j]]++;
	}
	for (i = 'a'; i <= 'z'; i++) {
		na[c[i] % 4]++;
	}
	if (na[1] + na[3] != (h % 2) * (w % 2)) {puts("No"); return 0;}
	if ((na[2] + na[3]) * 2 > h * (w % 2) + w * (h % 2) - (h % 2) * (w % 2)) {puts("No"); return 0;}
	puts("Yes");
    return 0;
}