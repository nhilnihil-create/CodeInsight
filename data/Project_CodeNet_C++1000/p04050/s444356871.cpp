#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 1e9;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < m; i++){
		cin >> a[i];
		if (a[i] & 1)
			cnt ++;
	}
	if (m == 1){
		if (n == 1)
			return cout << "1\n1\n1", 0;
		cout << a[0] << '\n' << 2 << '\n' << a[0]-1 << " " << 1 << '\n';
		return 0;
	}
	if (cnt > 2)
		return cout << "Impossible\n", 0;
	for (int i = 1; i < m; i++)
		if (a[i] & 1)
			swap(a[0], a[i]);
	for (int i = 1; i < m-1; i++)
		if (a[i] & 1)
			swap(a[i], a[m-1]);
	for (int i = 0; i < m; i++)
		cout << a[i] << " \n"[i == m-1];
	a[0] ++, a[m-1] --;
	if (a[m-1] == 0)
		m --;
	cout << m << '\n';
	for (int i = 0; i < m; i++)
		cout << a[i] << " \n"[i == m-1];
}
