#include<iostream>
#include<cstdio>
#include<math.h>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<set>
#include<map>
#define INF 999999
#define EPS 1.0e-6

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int, P> PP;

int n;
int p[105000];

int main()
{
	cin >> n;
	vector<int>change;
	
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		if (p[i] == i)change.push_back(i);
	}
	int ans = 0;
	if (!change.empty())ans++;
	for (int i = 1; i < change.size(); i++) {
		if (change[i] != change[i - 1] + 1) {
			ans++;
		}
		else change[i]--;
	}
	cout << ans << endl;

	return 0;
}