#include <iostream>
using namespace std;
 
int main() {
	string s;
	cin >> s;
	int a, z;
 
	bool flag = true;
	for (int i = 0; i < s.size(); i++) 
	{
		if (s[i] == 'A' && flag) 
		{
			a = i;
			flag = false;
		}
		else if (s[i] == 'Z') z = i;
	}
	cout << z - a + 1 << endl;
}