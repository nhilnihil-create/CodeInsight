#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int N = 505;
const int INF = 3000;
char arr[N][N];
char SYM[] = "RYGB";
int n, m, d;

int main()
{                                                     
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> d;

	if (d % 2 == 1) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = SYM[(i + j) % 4];
	}
	else {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int new_x, new_y;
				if ((i + j) % 2 == 0) {
					new_x = (i + j + INF) / 2;
					new_y = (i - j + INF) / 2;
				}
				else {
					new_x = (i + j + 1 + INF) / 2;
					new_y = (i - j + 1 + INF) / 2;
				}
				int new_d = d / 2;

				int x_sqr = new_x / new_d;
				int y_sqr = new_y / new_d;

				if (x_sqr % 2 == 0)
					arr[i][j] = SYM[y_sqr % 4];
				else 
					arr[i][j] = SYM[(y_sqr + 2) % 4];
			}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}
