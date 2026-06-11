#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
#include<queue>
#include<algorithm>
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
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
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


	int N = getint(), X = getint();
	ll kotae = 0;
	int A[2002], B[2001];
	rep(i, N) {
		A[i] = getint();
		kotae += A[i];
		B[i] = 1;
	}

	int dai[2002], shou[2002];
	rep(i, N - 1) dai[i + 1] = i;
	dai[0] = N - 1;
	rep1(i, N - 1) shou[i - 1] = i;
	shou[N - 1] = 0;

	queue<int> P[2], Q[2];
	rep(i, N) {
		int a = i - 1 < 0 ? N - 1 : i - 1;
		int b = i + 1 >= N ? 0 : i + 1;
		if (A[a] < A[i] && A[i] >= A[b]) {
			P[0].push(i);
		}
		if (A[a] > A[i] && A[i] <= A[b]) {
			Q[0].push(i);
		}
	}

	ll kari = kotae;
	rep(i, N) {
		int mae = i & 1;
		int tugi = mae ^ 1;
		while (P[mae].size()) {
			int j = P[mae].front();
			P[mae].pop();
			kari -= A[j];
			if (B[j] >= 2) {
				B[j]--;
				P[tugi].push(j);
			}
			else {
				B[j] = 0;
				int l = j - 1 < 0 ? N - 1 : j - 1;
				l = shou[l];
				int l2 = l - 1 < 0 ? N - 1 : l - 1;
				int r = j + 1 >= N ? 0 : j + 1;
				r = dai[r];
				int r2 = r + 1 >= N ? 0 : r + 1;
				if (A[l2] < A[r2]) {
					int r3 = r2 + 1 >= N ? 0 : r2 + 1;
					r3 = dai[r3];
					int r4 = r3 + 1 >= N ? 0 : r3 + 1;
					if (A[r2] >= A[r4]) P[tugi].push(r2);
				}
				else {
					int l3 = l2 - 1 < 0 ? N - 1 : l2 - 1;
					l3 = shou[l3];
					int l4 = l3 - 1 < 0 ? N - 1 : l3 - 1;
					if (A[l4] < A[l2]) P[tugi].push(l2);
				}
				dai[l] = r;
				shou[r] = l;
			}
		}
		while (Q[mae].size()) {
			int j = Q[mae].front();
			Q[mae].pop();
			B[j]++;
			kari += A[j];
			int l = j - 1 < 0 ? N - 1 : j - 1;
			l = shou[l];
			int l2 = l - 1 < 0 ? N - 1 : l - 1;
			int r = j + 1 >= N ? 0 : j + 1;
			r = dai[r];
			int r2 = r + 1 >= N ? 0 : r + 1;
			if (A[l2] > A[j] && A[j] <= A[r2]) {
				Q[tugi].push(j);
			}
		}
		kari += X;
		chmin(kotae, kari);
	}

	printf("%lld\n", kotae);

	Would you please return 0;
}