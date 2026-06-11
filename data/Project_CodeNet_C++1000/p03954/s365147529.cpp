#include<bits/stdc++.h>
using namespace std;
const int maxN = 3e5 + 13;
int n, arr[maxN], a[maxN];
bool can (int x) {
    for (int i = 0; i < 2 * n - 1; i++)
	arr[i] = (a[i] >= x);
    int lst = arr[n - 1];
    int l = n - 2;
    int r = n;
    while (l >= 0 && arr[l] == arr[r] && arr[l] != lst) {
	lst = arr[l];
	l--;
	r++;
    }
    /* cout << x << " " << lst << endl;
    for (int i = 0; i < 2 * n - 1; i++)
	cout << arr[i] << " ";
	cout << endl;
    */
    return !lst;
}
    
int main () {
    cin >> n;
    for (int i = 0; i < 2 * n - 1; i++)
	cin >> a[i];
    int l = 0, r = 2 * n;
    while (r - l > 1) {
	int mid = l + r >> 1;
	if (can(mid))
	    r = mid;
	else
	    l = mid;
    }
    cout << l << endl;
}
