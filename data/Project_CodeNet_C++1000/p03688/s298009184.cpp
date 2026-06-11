//IOI 2021
//labriz kon code ra, ham paye ie AC manam, AC age yari kone ta sob man code miznm :)
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100 * 1000 + 17;

int n, a[MAXN], cnt[MAXN];
set<int> s;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], cnt[a[i]]++, s.insert(a[i]);
	if (s.size() == 1) {
		int t = *s.begin();
		if (t <= n / 2 || t == n - 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	else if (s.size() == 2) {
		int t1 = *s.begin();
		s.erase(s.begin());
		int t2 = *s.begin();
		if (t2 - t1 == 1 && t2 <= cnt[t1] + (cnt[t2] / 2) && cnt[t1] + 1 <= t2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	else
		cout << "No" << endl;
	return 0;
}
