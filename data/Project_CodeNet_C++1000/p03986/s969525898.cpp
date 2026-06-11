#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int main()
{
	cin >> s;
	int snum = 0, tnum = 0;
	int ans = s.size();
	int i = 0;
	int tag = 0;
	while (i < s.size())
	{
		if (s[i] == 'S') {
			while (s[i] == 'S' && i < s.size()) {
				snum++; i++;
			}
			while (s[i] == 'T' && i < s.size()) {
				tnum++; i++;
			}
			if (tnum >= snum) {//s用完
				ans -= snum * 2;
				snum = tnum = 0;
			}
			else {//s没用完，留给下一次
				ans -= tnum * 2;
				snum -= tnum;
				tnum = 0;
			}
		}
		else i++;
	}
	cout << ans;
	return 0;
}

