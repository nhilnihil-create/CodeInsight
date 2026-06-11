#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define mod 1e9 + 7
#define ll long long
#define all(c) c.begin(), c.end()
#define peek(v)			\
    for (auto i : v) 	\
        cout << i << ' ';
#define rep(i, begin, end)		\
    for (__typeof(end)			\
    i = (begin) - ((begin) > (end));	\
    i != (end) - ((begin) > (end));		\
    i += 1 - 2 * ((begin) > (end)))

void solve() 
{
	int a,b;
	char op;
	cin >> a >> op >> b;
	if(op=='+') cout << a+b;
	else if(op=='-') cout << a-b;
	else cout << -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}