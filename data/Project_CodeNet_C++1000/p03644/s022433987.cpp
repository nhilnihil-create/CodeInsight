#include <bits/stdc++.h>

using namespace std;
#define NIL -1
#define ll long long
#define MAX 100
#define pb push_back

int main()
{
	int n;
	cin >> n;
	int m=-1;
	int ans = 0;
	for(int i=1; i<=n; i++) {
		int x = i;
		int cnt = 0;
		while(x%2==0) {
			x/=2;
			cnt++;
		}
		if(m < cnt) {
			ans = i;
			m = cnt;
		}
	}
	cout << ans<< endl;
	return 0;
}
