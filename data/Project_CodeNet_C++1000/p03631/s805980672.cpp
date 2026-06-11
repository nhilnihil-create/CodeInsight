#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string S;
	cin >> S;

	string rS = S;
	reverse(rS.begin(), rS.end());

	if (S == rS)cout << "Yes" << endl;
	else cout << "No" << endl;
}