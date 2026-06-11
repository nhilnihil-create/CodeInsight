#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)


int main()
{
	int n, l; cin >> n >> l;
	string S[n];
	rep(i, n) cin >> S[i];
	sort(S, S+n);
	rep(i, n) cout << S[i];
	cout << endl;
}

