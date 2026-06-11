#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxN = 1e5 + 13;
int n, arr[maxN], a[maxN], m, k;
void pw (int b) {
    int ret[maxN], tmp[maxN];
    for (int i = 0; i < n - 1; i++)
	ret[i] = arr[i];
    for (; b; b >>= 1) {
	if (b & 1) {
	    for (int i = 0; i < n - 1; i++)
		tmp[i] = ret[i];
	    for (int i = 0; i < n - 1; i++) 
		ret[i] = tmp[arr[i]];
	    
	}
	for (int i = 0; i < n - 1; i++)
	    tmp[i] = arr[i];
	for (int i = 0; i < n - 1; i++)
	    arr[i] = tmp[arr[i]];
    }

    for (int i = 0; i < n - 1; i++)
	arr[i] = ret[i];
}

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
	cin >> a[i];
    }
    iota(arr, arr + n - 1, 0);
    cin >> m >> k;;
    for (int i = 0; i < m; i++) {
	int x;
	cin >> x;
	x--;
	swap(arr[x], arr[x - 1]);
    }
    pw(k - 1);
    int lst = a[0];
    for (int i = 0; i < n; i++) {
	cout << lst << '\n';
	lst += a[arr[i] + 1] - a[arr[i]];
    }
    
}
					  
