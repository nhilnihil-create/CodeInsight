#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	vector<char> alphabet{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
						  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	string s;
	cin >> s;

	bool flag = false;

	rep(i, alphabet.size())
	{
		rep(j, s.length())
		{
			if (alphabet[i] == s[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << alphabet[i] << endl;
			return 0;
		}
		flag = false;
	}
	cout << "None" << endl;
	return 0;
}