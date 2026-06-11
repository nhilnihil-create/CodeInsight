#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s, as = "\0";

	cin >> s;

	for (size_t i = 0; i < s.length(); i += 2)
	{
		as += s[i];
	}
	
	cout << as << endl;

	return 0; 
}