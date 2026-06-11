//#include<bits/stdc++.h>
#include<cstdio>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

const int dm = 1 << 21;
char dn[dm], * di = dn;
inline void putint(int X) {
	int keta = 0;
	char C[10];
	while (X) {
		*(C + keta) = '0' + X % 10;
		X /= 10;
		keta++;
	}
	for (int i = keta - 1; i >= 0; i--)* di++ = (*(C + i));
	*di++ = '\n';
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N, X;
	scanf("%d", &N);
	scanf("%d", &X);

	if (X == 1 || X == N * 2 - 1) {
		printf("No");
	}
	else {
		*di++ = 'Y';
		*di++ = 'e';
		*di++ = 's';
		*di++ = '\n';
		if (N == 2) {
			putint(1);
			putint(2);
			putint(3);
		}
		else if (X != 2) {
			int k = 2;
			rep(i, N - 2) {
				if (k == X - 1) k += 3;
				putint(k++);
			}
			putint(X - 1);
			putint(X);
			putint(X + 1);
			putint(1);
			rep(i, N - 3) {
				if (k == X - 1) k += 3;
				putint(k++);
			}
		}
		else {
			int k = 4;
			rep(i, N - 2) {
				putint(k++);
			}
			putint(3);
			putint(2);
			putint(1);
			putint(2 * N - 1);
			rep(i, N - 3) {
				putint(k++);
			}
		}
		fwrite(dn, 1, di - dn, stdout);
	}


	Would you please return 0;
}