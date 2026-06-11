#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 13;
int n, m, a[maxN], cnt;
int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
	cin >> a[i];
	if (a[i] % 2 == 1)
	    cnt++;
    }
    if (cnt > 2)
	return cout << "Impossible" << endl, 0;
    if (m == 1) {
	cout << a[0] << '\n';
	if (a[0] == 1) {
	    cout << 1 << '\n';
	    cout << 1 << '\n';
	    return 0;
	}
	cout << 2 << '\n';
	cout << 1 << " " << a[0] - 1 << '\n';
	return 0;
    }
    if (m == 2) {
	cout << a[0] << " " << a[1] << '\n';
	if (a[0] == 1) {
	    cout << 1 << '\n';
	    cout << a[1] + 1 << '\n';
	}
	else {
	    cout << 2 << '\n';
	    cout << a[0] - 1 << " " << a[1] + 1 << '\n';
	}
	return 0;
    }
	    
    for (int i = 0; i < m - 1; i++) {
	if (a[i] % 2 == 1)
	    swap(a[i], a[i + 1]);
    }
    for (int i = m - 2; i > 0; i--) {
	if (a[i] % 2 == 1)
	    swap(a[i], a[i - 1]);
    }
    for (int i = 0; i < m; i++)
	cout << a[i] << " ";
    cout << '\n';
    if (a[0] == 1) {
	cout << m - 1 << '\n';
	for (int i = 1; i < m - 1; i++)
	    cout << a[i] << " ";
	cout << a[m - 1] + 1 << '\n';
    }
    else {
	cout << m << '\n';
	cout << a[0] - 1 << " ";
	for (int i = 1; i < m - 1; i++)
	    cout << a[i] << " ";
	cout << a[m - 1] + 1 << '\n';
    }
}
