#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<queue>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 100010;
int cnt[MAX];
pii cntM[MAX];

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> X(N);
	int mm = 0;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		if (X[i]%M == 0) mm++;
		else cnt[X[i]]++;
	}
	for (int i = 0; i < MAX; i++) {
		cntM[i%M].first += cnt[i];
		if (cnt[i]%2 == 1) cntM[i%M].second++;
	}
	int ans = mm/2;
	for (int i = 1; i <= M/2; i++) {
		if (i == M/2 && M%2 == 0) ans += cntM[i].first/2;
		else {
			int tmp = min(cntM[i].first, cntM[M-i].first);
			ans += tmp;
			int index = i;
			if (cntM[i].first <= tmp) index = M-i;
			if (cntM[index].second >= tmp) {
				ans += (cntM[index].first - (cntM[index].second))/2;
			} else {
				ans += (cntM[index].first-tmp)/2;
			}
		} 
	}
	cout << ans << endl;
	return 0;
}
