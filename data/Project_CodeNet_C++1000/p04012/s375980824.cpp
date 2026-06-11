#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int i, j, k ;
    map<char,int>mp;
    string s;
    cin >> s;
    for(i=0; i<s.size(); i++)
    {
        mp[s[i]]++;
    }
    j=0;
    for(i=0; i<s.size(); i++)
    {
        if(mp[s[i]]%2!=0)
        {
            j=1;

            break;
        }
    }
    if(j)
        cout << "No";
    else
        cout << "Yes";

    return 0;
}