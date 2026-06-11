#include <iostream>
#include <cassert>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    bool result = true;
    int cnt;
    string w;
    cin >> w;
    for (int i = 0; i < 26; i++)
    {
        cnt = 0;
        for (int j = 0; j < w.length(); j++)
        {
            if (w[j] == 'a' + i)
            {
                cnt++;
            }
        }
        if (cnt % 2 == 1)
        {
            result = false;
        }
    }

    if (result == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}