#include <bits/stdc++.h>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	string ans;
	if( A.size() > B.size() ) ans = "GREATER";
	else if( A.size() < B.size() ) ans = "LESS";
	else if( A > B ) ans = "GREATER";
	else if( A < B ) ans = "LESS";
	else ans = "EQUAL";

	cout << ans << endl;
}
