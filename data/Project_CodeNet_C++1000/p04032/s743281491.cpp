#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <math.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int end = str.length();
    for (int i = 0; i < end - 1; ++i)
    {
        if( str[i] == str[i + 1] ){
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }
        if( i < end - 2 && str[i] == str[i + 2] ){
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}