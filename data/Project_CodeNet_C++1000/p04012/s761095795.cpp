#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int main()
{
  string c;
    int ara[26] = {},j;
    cin>>c;
    int len = c.size();
    for(int i = 0; i< len; i++)
    {
        j = 0;
        j = c[i] - 'a';
        ara[j]++;
    }
    bool ok = true;
    for(int j = 0; j<26; j++)
    {
        if(ara[j]%2!=0)
            ok = false;
    }
    if(ok == true )
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}






