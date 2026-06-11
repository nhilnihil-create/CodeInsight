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
    int s, l;
    cin >> s >> l;
    vector<int> num(10);
    for (int i = 0; i < l; i++)
    {
        int tem;
        cin >> tem;
        num[tem]++;

    }

    for (int i = s;; i++) {
        string strr = to_string(i);
        bool temp = true;

        for (int j = 0; j < strr.size(); j++) {
            if (num[strr[j] - '0'] == 1) {
                temp = false;
                break;
            }
        }
        if (temp == true) {
            cout << i;
            break;
        }
    }
    

    
    
}