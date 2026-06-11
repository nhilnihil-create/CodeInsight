#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <list>
#include <cassert>
#include <climits>

using namespace std;

int main()
{
    int numm[30] = { 0 };
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        numm[s[i] - 'a'] += 1;

    }

    for (int i = 0; i < 26; i++)
    {
        if (numm[i]%2 != 0)
        {
            cout << "No";
            return 0;

        }
    }
    cout << "Yes";
    return 0;
}
