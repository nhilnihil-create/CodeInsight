#include <stdio.h>
#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;

const int N = (int)3e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9;
const ll INF = (ll)1e18;

void no(){
	cout << "No";
	exit(0);
}

int n, a[3];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i){
		int x, y = 0;
		cin >> x;
		while(x % 2 == 0)
			y++, x /= 2;
		a[min(y, 2)]++;
	}

	if(a[0] > a[2] + 1)
		no();
	if(a[0] == a[2] + 1 && a[1])
		no();
	cout << "Yes";

	return 0;
}