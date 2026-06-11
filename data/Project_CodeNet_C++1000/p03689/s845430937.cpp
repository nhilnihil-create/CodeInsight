#include <iostream>
#include <cstdio>
using namespace std;
 
int n, m, r, c;
int main()
{
	int i, j;
	cin >> n >> m >> r >> c;
	if (m % c > 0) {
		cout << "Yes" << endl;
		for (j = 0; j < n; j++) {
			for (i = 0; i < m; i++) {
				if (i % c == 0) printf("%d ", 1000 * (c - 1) - 1);
				else printf("-1000 ");
			}
			printf("\n");
		}
	} else if (n % r > 0) {
		cout << "Yes" << endl;
		for (j = 0; j < n; j++) {
			for (i = 0; i < m; i++) {
				if (j % r == 0) printf("%d ", 1000 * (r - 1) - 1);
				else printf("-1000 ");
			}
			printf("\n");
		}
	} else {
		cout << "No";
	}
    return 0;
}