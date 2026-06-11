#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int fro=0, end=s.size()-1;
    for (int i=0;i<s.size();i++)
    {
        if (s.at(i)=='A')
        {
            fro=i;
            break;
        }
    }
    for (int i=s.size()-1;i>=0;i--)
    {
        if (s.at(i)=='Z')
        {
            end=i;
            break;
        }
    }
    cout << end-fro+1 << endl;
}