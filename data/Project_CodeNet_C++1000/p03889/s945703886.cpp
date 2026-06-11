#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string s, temp;

void change(char &ch);

int main(void)
{
	cin >> s;
	temp = s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++)
		change(s[i]);
	if (s == temp)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
	//system("pause");
	return 0;
}

void change(char &ch)
{
	if (ch == 'b')
		ch = 'd';
	else if (ch == 'd')
		ch = 'b';
	else if (ch == 'p')
		ch = 'q';
	else if (ch == 'q')
		ch = 'p';
}