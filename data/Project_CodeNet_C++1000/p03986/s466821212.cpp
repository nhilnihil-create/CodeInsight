#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size()-1;i++)
	{
		if(s.size()==2)
			break;
		if (s[i] == 'S'&&s[i + 1] == 'T')
		{
			s.erase(i, 2);
			if(i==0)
				i=-1;
			else
				i -= 2;
		}
	}
	if(s=="ST")
		cout<<'0'<<endl;
	else
		cout << s.size() << endl;	
    return 0; 
}
