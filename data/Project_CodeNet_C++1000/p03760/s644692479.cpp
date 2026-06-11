#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 7;

int main()
{
	int d1 = -1, d2=-1;
	string st1, st2;
	cin >> st1 >> st2;
	int k = st1.size() - 1;
	while (d1<=int(st1.size()-1)||d2<=int(st2.size()-1))
	{
		if(++d1<=st1.size()-1)cout << st1[d1];
		if (++d2 <= st2.size() - 1)cout << st2[d2];
	}
}