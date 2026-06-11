#include<iostream>
using namespace std;

int main()
{
	string A, B, C;
	string ans = "000";

	cin >> A >> B >> C;
	ans.at(0) = A.at(0);
	ans.at(1) = B.at(0);
	ans.at(2) = C.at(0);
	cout << ans << endl;
	return 0;
}