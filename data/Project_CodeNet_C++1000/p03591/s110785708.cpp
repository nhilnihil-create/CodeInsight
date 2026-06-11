#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	string S; cin >> S;
	if (S.size() >= 4) {
		if (S[0] == 'Y' && S[1] == 'A' && S[2] == 'K' && S[3] == 'I') cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else cout << "No" << endl;
}