#include <iostream>
#include<string>
using namespace std;

int main()
{
	string S;
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		int len = S.length() - i;
		if (len % 2 == 0 && i>0) {
			//文字数が偶然のとき
			string S1 = S.substr(0, len / 2);
			string S2 = S.substr(len / 2, len / 2);
			//cout << S1 << " " << S2 << endl;
			if (S1 == S2) {
				cout << len << endl;
				return 0;
			}
		}

	}
}


