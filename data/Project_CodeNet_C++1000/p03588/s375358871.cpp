#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)

// Write From This Line
int main()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	int m = -1;	
	// a[i]が一番小さいやつの a[i] + b[i]が答え
	int ans = 0;
	rep(i,n) {
		if(m < a[i]){
		ans = a[i] +b[i];
			m = a[i];
		}
	}
	cout << ans << endl;
}
