#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    string t = "";
    int cnt = 0;
    for (int i = s.size()-1; i >= 0; i--)
    {
        if (s[i] == 'B')
        {
            cnt++;
        }else if (cnt != 0)
        {
            cnt--;
        }else if (s[i] != 'B' && cnt == 0)
        {
            t = s[i]+t;
        }
        
        
    }
    cout << t << endl;
}
    