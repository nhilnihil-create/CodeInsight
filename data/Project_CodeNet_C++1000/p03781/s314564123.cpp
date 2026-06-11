#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n;i >= 0;i--)
#define for1(i, m, n) for(int i = m;i < n;i++)
#define ll long long
#define endl '\n'
using namespace std;


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
    int x;
    cin >> x;
    int i = 0;
    while(true) {
        if (x <= i * (i + 1) / 2) {
            cout << i << endl;
            return 0;
        }
        i++;
    }
	return 0;
}