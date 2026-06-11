#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string O, E;
	cin >> O >> E;
	for (int i = 0; i < O.size() - 1; i++) {
		printf("%c%c", O[i], E[i]);
	}
	if (E.size() == O.size()) printf("%c%c\n", O[O.size() - 1], E[E.size() - 1]);
	else printf("%c\n", O[O.size() - 1]);

	return 0;
}
