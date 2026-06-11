#include<iostream>
#include<algorithm>
using namespace std;
bool a[26];
int main()
{

	string s; cin >> s; int f = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		a[s[i] - 'a']=true;
	}
	for (int i = 0; i < 26; ++i)
	{
		if (!a[i]) {
			cout << (char)(i + 'a');
			f = 1;
			break;
			
		}
	}
	if (!f)
		cout << "None";
}