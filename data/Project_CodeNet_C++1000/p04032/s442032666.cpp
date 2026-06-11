#include <iostream>
#include <string>

using namespace std;

int main()	{
  	string s;
  	cin >> s;
  	int x = -1, y = -1;
	for (int i = 1; s[i] != '\0'; i++)	{
      	if (s[i] == s[i - 1])	{
          	x = i - 1;
          	y = i;
          	cout << x + 1 << " " << y + 1 << endl;
          	return 0;
        }
    }
  	for (int i = 0; i < s.length() - 2; i++)	{
    	if (s[i + 2] == s[i])	{
			x = i;
          	y = i + 2;
          	cout << x + 1 << " " << y + 1 << endl;
          	return 0;
        }
    }
	cout << -1 << " " << -1 << endl;
  	return 0;
}