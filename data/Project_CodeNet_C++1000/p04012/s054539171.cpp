/* C++ Program to Find the Frequency of Characters in a String */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int i;
    int fre[365] = {0};
    cin>>s;
    for(i=0;s[i]!='\0';i++)
    {
        fre[s[i]]++;
    }

    int cnt = 0;
    for(i=0;i<365;i++)
    {
        if(fre[i]%2!=0)
        {
            cnt = 1;
            break;
        }
    }

    if(cnt==1)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}
