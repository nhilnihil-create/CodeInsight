
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	string ws[] = { "dream", "dreamer", "erase", "eraser" };
	string S; cin >> S;
	reverse(S.begin(), S.end());
	for (int i = 0; i < 4; ++i) {
		reverse(ws[i].begin(), ws[i].end());
	}
	int Sz = S.size();
	for (int i = 0; i < Sz; ++i) {
		for (int w = 0; w < 4; ++w) {
			if (i + ws[w].size() <= Sz) {
				string str = S.substr(i, ws[w].size());
				if (ws[w] == str) {
					i = i + ws[w].size() - 1;
					break;
				}
			}
			if (w == 3) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;;

}