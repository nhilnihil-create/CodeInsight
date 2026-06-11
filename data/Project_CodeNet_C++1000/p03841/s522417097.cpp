#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<functional>
using namespace std;
#define INF 1e15
#define MOD 1000000007
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define END system("PAUSE");return 0
int n, cnt, b[555 * 555], x = 1;
P a[555];
signed main() {
	cin >> n;
	rep(i, n) {
		cin >> a[i].first;
		a[i].second = i + 1;
		b[a[i].first] = i + 1;
	}
	sort(a, a + n);
	rep(i, n) {
		rep(j, a[i].second - 1) {
			if (!b[x])b[x] = a[i].second;
			else x++,j--;
		}
	}
	x = n * n;
	for (int i = n - 1; i >= 0; i--) {
		rep(j, n - a[i].second) {
			if (!b[x])b[x] = a[i].second;
			else {
				x--;
				j--;
			}
		}
	}
	rep(i, n) {
		int cnt = 0;
		for (int j = 1; j <= n * n; j++) {
			if (b[j] == a[i].second)cnt++;
			if (a[i].first == j) {
				if (a[i].second != cnt) {
					puts("No");
					END;
				}
			}
		}
	}
	puts("Yes");
	for (int i = 1; i <= n * n; i++) {
		if (i != 1)cout << " ";
		cout << b[i];
	}
	cout << endl;
	END;
}
