
#include<bits/stdc++.h>

#define sz(s)               (int)s.size()
using namespace std;
int main()
{
	long long l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	if (l1*r1 > l2*r2) cout << l1*r1;
	else  if (l1*r1 <l2*r2) cout << l2*r2;
	else cout << l2*r2;

}