#include <bits/stdc++.h>

#define X first
#define Y second
#define MP make_pair

using namespace std;

typedef long long ll;

const int N = 1e5 + 12;
const ll mod = 1e9 + 7;

int n, a[N];

int main () {
	scanf("%d\n", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", a + i);
	sort(a, a + n, [](int x, int y){return x > y;});
	int z = 0;
	while(z < n && a[z + 1] > z + 1)
		z++;
	int x = a[z] - z, y = 0;
	while(z + y < n && a[z + y] > z)
		y++;
	if(x % 2 == 1 && y % 2 == 1)
		cout << "Second";
	else
		cout << "First";
}
