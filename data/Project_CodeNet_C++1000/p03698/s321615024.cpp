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

	set<char> Sc;
	for (int i = 0; i < S.length(); i++) {
		Sc.insert(S[i]);
	}

	if (Sc.size() == S.length()) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

}




