#include <bits/stdc++.h>
using namespace std;

const int _A = 100000;
int L[100009], A[100009];
long long ans[100009], F1[100009], F2[100009];
vector<int> S;

void upd(long long F[], int x, int y) {
	for(int i=x; i<=_A; i+=(i&-i)) F[i] += y;
}

long long get(long long F[], int x) {
	long long ret = 0;
	for(int i=x; i>=1; i-=(i&-i)) ret += F[i];
	return ret;
}

int getx(int x) {
	return lower_bound(S.begin(), S.end(), x) - S.begin() + 1;
}

int main() {
	int N; scanf("%d",&N);
	for(int i=1, m=0; i<=N; i++) {
		scanf("%d",&A[i]);
		S.push_back(A[i]);
		if(m < A[i]) L[i] = A[i] - m, m = A[i];
	}
	sort(S.begin(), S.end());
	S.resize(unique(S.begin(), S.end()) - S.begin());
	long long s = 0;
	for(int i=N; i>=1; i--) {
		int j = getx(A[i]), k = getx(A[i] - L[i] + 1);
		upd(F1, j, +1); upd(F2, j, A[i]);
		
		if(L[i]) {
			long long cnt = get(F1, _A) - get(F1, k - 1);
			long long sum = get(F2, _A) - get(F2, k - 1);
			ans[i] = sum - cnt * (A[i] - L[i]) - s;
			s += sum - cnt * (A[i] - L[i]) - s;
		}
	}
	for(int i=1; i<=N; i++) printf("%lld\n", ans[i]);
	return 0;
}