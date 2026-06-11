#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int len = s.length();
    for(int i=1;i<len;i++)
    {
        string temp = s.substr(0 , len-i);
        if( temp.length()%2== 1)
        {
            continue;
        } else
        {
            int tl = temp.length();
            string temp2 = temp.substr(0 , tl/2);
            temp2 = temp2 + temp2;
            if( temp2 == temp)
            {
                cout<<temp2.length();
                return 0;
            }
        }
    }
}