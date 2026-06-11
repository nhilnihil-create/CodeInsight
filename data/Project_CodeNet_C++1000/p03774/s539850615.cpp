#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	pair<ll, ll> students[55];
	pair<ll, ll> checkpoints[55];

	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &students[i].first, &students[i].second);
	for (int i = 0; i < m; i++)
		scanf("%lld%lld", &checkpoints[i].first, &checkpoints[i].second);

	for (int i = 0; i < n; i++) {
		ll min = 1e9, index = 0;
		for (int j = 0; j < m; j++) {

			if (abs(students[i].first - checkpoints[j].first)
					+ abs(students[i].second - checkpoints[j].second) < min) {

				min = abs(students[i].first - checkpoints[j].first)
						+ abs(students[i].second - checkpoints[j].second);
				index = j+1;

			}

		}
		printf("%lld\n", index);
	}

}
