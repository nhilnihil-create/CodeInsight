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

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	int A = 0;
	if (ci - cn + 16 > cm) while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';
	else while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';
	return A;
}


int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();

	int A[301][301];
	rep1(i, N) {
		rep1(ii, N) {
			A[i][ii] = getint();
		}
	}

	//int shouryaku[301][301] = {};
	//rep1(k, N) {
	//	rep1(i, N) {
	//		if (k == i) continue;
	//		rep1(j, i - 1) {
	//			if (k == j) continue;
	//			if (A[i][j] > A[i][k] + A[k][j]) {
	//				printf("-1");
	//				return 0;
	//			}
	//			else if (A[i][j] == A[i][k] + A[k][j]) {
	//				shouryaku[i][j] = 1;
	//			}
	//		}
	//	}
	//}

	//ll goukei = 0;
	//rep1(i, N) {
	//	rep1(ii, i - 1) {
	//		if (shouryaku[i][ii] == 0) goukei += A[i][ii];
	//	}
	//}

	ll goukei = 0;
	rep1(i, N) {
		rep1(j, i - 1) {
			bool OK = 1;
			rep1(k, N) {
				if (k == j || k == i) continue;
				if (A[i][j] > A[i][k] + A[k][j]) {
					printf("-1");
					return 0;
				}
				else if (A[i][j] == A[i][k] + A[k][j]) {
					OK = 0;
					break;
				}
			}
			if(OK) goukei += A[i][j];
		}
	}

	printf("%lld", goukei);

	Would you please return 0;
}