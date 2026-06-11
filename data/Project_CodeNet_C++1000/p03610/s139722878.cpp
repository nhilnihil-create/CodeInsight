#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i += 2)
		cout << s[i];
	return 0;
}