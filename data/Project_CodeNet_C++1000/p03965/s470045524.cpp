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

    int len = s.length();
    int score = 0;
    for(int i = 0; i < len; i ++)
    {
    	if(i % 2 == 0)
    	{
    		if(s[i] == 'p')
    			score --;
    	}
    	else if(i % 2 == 1)
    	{
    		if(s[i] == 'g')
    			score ++;
    	}
    }
    cout << score << endl;
}