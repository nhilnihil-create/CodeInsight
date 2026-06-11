#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<memory.h>
using namespace std;
typedef long long ll;
const int Max = 4e5 + 5;

int lst[Max];

int main()
{
	string str;
	cin >> str;
	reverse(str.begin(), str.end());
	int g = 0;
	int f = 1;
	while (g < str.size())
	{
		if (g + 5 > str.size())
		{
			f = 0;break;
		}
		else if (str.substr(g, 5) == "maerd" || str.substr(g, 5) == "esare")
		{
			g += 5;
		}
		else if(g+6<=str.size())
		{
			if (str.substr(g,6 ) == "resare")g += 6;
			else if (g + 7 <= str.size())
			{
				if (str.substr(g, 7) == "remaerd")g += 7;
				else
				{
					f = 0;
					break;
				}
			}
			else
			{
				f = 0;break;
			}
		}
		else
		{
			f = 0;break;
		}
	}
	if (f) cout << "YES";
	else cout << "NO";
}