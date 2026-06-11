#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool debug = false;
	string exa[4] = { "dream",  "erase", "eraser","dreamer" };

	for (int i = 0; i < 4; i++)
	{
		reverse(exa[i].begin(), exa[i].end() );
	}

	reverse(s.begin(), s.end());


	int count = 0;
	bool result = true;
	string comp = "";

	if (debug) cout << s.size() << endl;

	for (int i = 0; i < s.size(); i++)
	{
		count++;
		comp += s[i];

		if(debug) cout << comp << endl;

		if (count >= 5)
		{
			for (int j = 0; j < 4; j++)
			{
				if (comp == exa[j])
				{
					count = 0;
					comp = "";
					break;
				}
			}
			
		}
		if (count > 7)
		{
			result = false;
			break;
		}
		if (i ==( s.size() - 1) && count > 0)
		{
			result = false;
		}
	}

	if (result)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

}