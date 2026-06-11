#include<iostream>
//#include<CastingInterop.h>
#include<string>
using namespace std;

int main()
{




	string s;
	bool t = true;
	cin >> s;
	for (int i = 97; i <= 122; i++)
	{
		t = true;
		for (int j = 0; j < s.length(); j++)
		{
			if (char(i) == s[j])
			{
				t = false;
				continue;
			}
		}
		if (t == true) {
			cout << char(i) ;
			return 0;
		}
	}
	if (t == false)
	{
		cout << "None" ;
		return 0;
	}
	
}