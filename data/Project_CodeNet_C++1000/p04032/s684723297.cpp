#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define endl "\n"
using namespace std;

int main()
{
    string s;
    cin >> s;

    int i;
    for(i = 0; i < s.length() - 1; i ++)
    {
    	if(s[i] == s[i + 1])
    	{
    		cout << i + 1 << " " << i + 2;
    		break;
    	}
    	else if(i + 2 < s.length() && s[i] == s[i + 2])
    	{
    		cout << i + 1 << " " << i + 3;
    		break;
    	}
    }

    if(i == s.length() - 1)
    	cout << "-1 -1" << endl;
}