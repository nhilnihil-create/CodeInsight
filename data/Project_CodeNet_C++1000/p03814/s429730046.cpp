#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int A_num, Z_num;
    for (int i = 0; i < S.size(); i++)
    {
        if (S.at(i) == 'A')
        {
            A_num = i;
            break;
        }
    }
    for (int i = 0; i < S.size(); i++)
    {

        if (S.at(i) == 'Z')
        {
            Z_num = i;
            
        }
    }
    cout << Z_num - A_num + 1 << endl;
}

