#include <iostream>
#include <string>

using namespace std;

void solve()
{
	string S;
	cin >> S;
	if (S[0] == 'Y' && S[1] == 'A' && S[2] == 'K' && S[3] == 'I')
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}

int main()
{
	solve();
	return(0);
}