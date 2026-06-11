#include <iostream>
#include <vector>
using namespace std;

long long N, M, K, a[100009], p[100009], x1[100009], x[100009], GG[100009]; vector<long long>J;

vector<long long>add(vector<long long>A1, vector<long long>A2) {
	vector<long long>A3 = A1;
	for (int i = 0; i < A1.size(); i++) {
		A3[i] = A2[A1[i]];
	}
	return A3;
}
vector<long long>rep(vector<long long>A2, long long P) {
	vector<long long>B1 = J, B2 = A2;
	for (int i = 0; i < 62; i++) {
		if ((P / (1LL << i)) % 2 == 1) { B1 = add(B1, B2); }
		B2 = add(B2, B2);
	}
	return B1;
}

int main() {
	cin >> N; for (int i = 0; i < N; i++) { cin >> a[i]; x1[i] = i; x[i] = i; }
	cin >> M >> K;
	for (int i = 1; i <= M; i++) {
		cin >> p[i]; p[i]--; swap(x[x1[p[i] - 1]], x[x1[p[i]]]);
		swap(x1[p[i] - 1], x1[p[i]]);
	}
	vector<long long>F;
	for (int i = 0; i < N - 1; i++)J.push_back(i);
	for (int i = 0; i < N - 1; i++)F.push_back(x[i]);
	vector<long long>G = rep(F, K);
	for (int i = 0; i < G.size(); i++) GG[G[i]] = i;
	long long I = a[0]; cout << I << endl;
	for (int i = 0; i < G.size(); i++) {
		I += a[GG[i] + 1] - a[GG[i]];
		cout << I << endl;
	}
	return 0;
}