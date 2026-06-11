#include <bits/stdc++.h>
using namespace std;

int nxt[200002], val[200002];

int main() {
	string A;
	cin >> A;
	int N = A.size(), cnt[256] = { 0 }, pos[256];
	memset(pos, -1, sizeof(pos));
	for (int i = N - 1; i >= 0; --i) {
		val[i] = min_element(cnt + 'a', cnt + 'z' + 1) - cnt;
		nxt[i] = pos[val[i]];
		cnt[A[i]] = *min_element(cnt + 'a', cnt + 'z' + 1) + 1;
		pos[A[i]] = i;
	}
	cout << (char)(min_element(cnt + 'a', cnt + 'z' + 1) - cnt);
	for (int i = pos[min_element(cnt + 'a', cnt + 'z' + 1) - cnt]; i != -1; i = nxt[i]) cout << (char)val[i];
}