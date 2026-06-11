#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S;
	cin >> S;

	string T = "CODEFESTIVAL2016";

	int count = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != T[i]) {
			count++;
		}
	}
	cout << count << endl;

}
