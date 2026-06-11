#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>
#define endl "\n"
using namespace std;




int main()
{
    int i,temp=0;
    string S;
    cin >> S;
    int freq[27]={};
    for (i = 0; i < S.length(); i++)
    {
        int c = S[i] - 96;
       // cout << c << endl;
        freq[(int)S[i]-96]++;
    }
    for (i = 0; i < 27; i++)
    {
        if (freq[i] % 2 != 0)
        {
            temp = 1;
            cout << "No\n";
            break;
        }
    }
    if (temp == 0)
    {
        cout << "Yes\n";
    }
}
