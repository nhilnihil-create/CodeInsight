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

using namespace std;

int main()
{
    string s;
    string temp = "";
    int currsiz = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1' || s[i] == '0') {
            temp += s[i];
            currsiz += 1;
        }
        if(currsiz>0 && s[i]=='B'){
            temp.pop_back();
            currsiz -= 1;

        }
        


    }
    cout << temp;

    
    
}