#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int posA, posZ;
    cin >> s;

    for(int i=0; ;i++)
    {
        posA = i;
        if(s[i]=='A') break;
    }

    for(int i=s.length(); ;i--)
    {
        posZ = i;
        if(s[i]=='Z') break;
    }
    cout << posZ - posA + 1 << endl;
    return 0;
}