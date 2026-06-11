#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;

string s;
stack<char> stk;

int main()
{
    cin >> s;
    long len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (stk.empty() || (stk.top() == 'S' && s[i] == 'S') || stk.top() == 'T')
            stk.push(s[i]);
        
        if (stk.top() == 'S' && s[i] == 'T')
            stk.pop();
    }
    cout << stk.size();
    
    return 0;
}
