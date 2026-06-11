#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long n, a[N], l[N], r[N];
int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	stack<long long> st;
	for (int i = 0; i < n; ++i)
	{
		while (!st.empty() && a[st.top()] > a[i])
		{
			r[st.top()] = i - 1;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty())
	{
		r[st.top()] = n - 1;
		st.pop();
	}
	for (int i = n - 1; i >= 0; --i)
	{
		while (!st.empty() && a[st.top()] > a[i])
		{
			l[st.top()] = i + 1;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty())
	{
		l[st.top()] = 0;
		st.pop();
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += (i - l[i] + 1) * (r[i] - i + 1) * a[i]; 
	}
	cout << ans << '\n';
	return 0;
}