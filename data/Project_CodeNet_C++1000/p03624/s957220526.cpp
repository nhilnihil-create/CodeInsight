#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
	string s; cin >> s; int n = s.length(); bool x = true;
	for (int i = 97; i <=122; i++)
	{
		 x = true;
		for (int j = 0; j < n; j++)
		{

			if (char(i) == s[j])
			{
				x = false;
				continue;

			}

		}
	
		if (x== true)
		{
			cout<<char(i)<<endl;
			return 0;
		}
	}
	if (x == false) {
		cout << "None" << endl;
		return 0;
	}
}
