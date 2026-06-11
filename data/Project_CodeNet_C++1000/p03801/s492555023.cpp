#include<iostream>
#include<map>
#include<set>

using namespace std;

typedef long long ll;

int N;
ll A[100000 + 10];
ll ans[100000 + 10];

map<ll, int> cnt, leftpos;
set<ll> S;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i], cnt[A[i]]++, S.insert(A[i]);
		if (cnt[A[i]] == 1)leftpos[A[i]] = i;
	}

	ll operation = 0;
	for (auto it = S.rbegin(); it != S.rend(); it++) {
		ll val = (*it);
		if (it != (--S.rend())) {
			operation += cnt[val];
			auto cpyit = it;
			cpyit++;
			ans[leftpos[val]] += operation * (val - (*cpyit));
			if (leftpos[(*cpyit)] > leftpos[val])leftpos[(*cpyit)] = leftpos[val];
		}
		else {
			operation += cnt[val];
			ans[leftpos[val]] += operation * (val - 0);
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}