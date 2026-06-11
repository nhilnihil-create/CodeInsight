#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
#include<utility>
#include<vector>

using namespace std;
//--------------------

int main() {
	string res = "Yes";
	string S; cin >> S;
	long mylen = S.length();

	for (int i = 0; i < mylen; i++) {
		if (S[i] == 'b' && S[mylen - 1 - i] != 'd') res = "No";
		if (S[i] == 'd' && S[mylen - 1 - i] != 'b') res = "No";
		if (S[i] == 'p' && S[mylen - 1 - i] != 'q') res = "No";
		if (S[i] == 'q' && S[mylen - 1 - i] != 'p') res = "No";
	}
	cout << res << endl;
}