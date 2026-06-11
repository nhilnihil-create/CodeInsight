#include <bits/stdc++.h>

using namespace std;

int a[260001];
int fa[260001];
int kol[260001];
int used[260001];
int zhanbolat[260001];
int wased[260001];
set <pair <int, int> > st;

int main () {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i ++) {
		cin >> a[i];
		fa[a[i]] += i;
		used[a[i]] = i;
		wased[a[i]] = i;
		kol[i] = i - 1;
		if (i > 1) st.insert (make_pair (a[i], i));
	}
	for (int i = 1;i <= n * n;i ++) {
		fa[i] += fa[i - 1];
		if (fa[i] > i) {
			cout << "No";
			return 0;
		}
	}
	for (int i = 1;i <= n * n;i ++) {
		if (used[i]) continue;
		if (!st.size ()) continue;
		int pos = st.begin () -> second;
		kol[pos] --;
		used[i] = pos;
		if (!kol[pos]) st.erase (st.begin ());
	}               
	for (int i = 1;i <= n;i ++) {
		kol[i] = n - i;
	}
	for (int i = 1;i <= n * n;i ++) {
		if (!used[i]) {
			for (int j = 1;j <= n;j ++) {
				if (kol[j] && zhanbolat[j]) {
					used[i] = j;
					kol[j] --;
					break;
				}               	
			}                       	
		}
		if (wased[i]) zhanbolat[wased[i]] = 1;
		if (!used[i]) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes\n";
	for (int i = 1;i <= n * n;i ++) cout << used[i] << ' ';
	return 0;
}