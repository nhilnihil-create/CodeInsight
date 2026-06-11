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
	int count;
	vector<int> alphabet(26);						// アルファベットは26文字
	string w;
	cin >> w;

	rep(i, w.length()) alphabet[int(w[i]) - 97]++;	// a(92)～z(122)を0～26にしてカウント

	rep(i, alphabet.size())
	{
		if (alphabet[i] % 2 != 0)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}