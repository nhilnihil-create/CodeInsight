#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
using namespace std;

int main(void)
{
    char s;
    for(int i = 1;i <= 12;i++)
    {
        cin >> s;
        if(i == 5){cout << " ";}
        cout << s;
    }
    cout << endl;
    return 0;
}