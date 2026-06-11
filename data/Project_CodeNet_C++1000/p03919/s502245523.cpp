#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
using namespace std;

int main(void)
{
    int h,w;
    char moji = 'A';
    string s;
    cin >> h >> w;
    for(int i = 1;i <= h;i++)
    {
        for(int j = 1;j <= w;j++)
        {
            cin >> s;
            if(s == "snuke"){cout << moji << i; return 0;}
            moji += 1;
        }
        moji = 'A';
    }
    return 0;
}