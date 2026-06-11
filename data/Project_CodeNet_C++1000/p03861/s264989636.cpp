#include<bits/stdc++.h>
using namespace std;

int main()
{
	using ll = long long;
	ll L, R, x;
	cin >> L >> R >> x;
	ll first = L - L%x + (L%x==0 ? 0 : x);
	ll last = R - R%x;
	cout << last/x - first/x + 1;
}
