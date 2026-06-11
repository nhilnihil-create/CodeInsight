#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

int ar[105];

int main() {
	int a, b, c, cnt = 0;
	cin >> a >> b >> c;
	ar[a] ++;
	ar[b] ++;
	ar[c] ++;
	for (int i = 1; i <= 100; i ++)
		cnt += ar[i] > 0;
	cout << cnt << endl;
	return 0;
}