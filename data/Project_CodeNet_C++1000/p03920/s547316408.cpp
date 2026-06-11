#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EPS (1e-10)
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

int main() {
	int n; scanf("%d", &n);
	int j = 1;
	while ((j + 1)*j / 2 < n)j++;
	while (n&&j>0&&n - j >= 0) {
		cout << j << endl;
		n -= j;
		j--;
	}
	if (n)cout << n << endl;
}