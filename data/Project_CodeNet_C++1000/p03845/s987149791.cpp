#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
 
void b_contest_with_drinks_easy(void) {
	int n, m;
	int sum = 0;
	int t[110];
	int p[110];
	int x[110];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		sum += t[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> p[i] >> x[i];
	}
 
	int sub = 0;
	for (int i = 1; i <= m; i++) {
		sub = t[p[i]] - x[i];
		cout << sum - sub << endl;
	}
}
 
int main()
{
	b_contest_with_drinks_easy();
    return 0;
}