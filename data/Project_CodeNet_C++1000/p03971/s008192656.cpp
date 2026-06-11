#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int a,b,t;
    int aa=0,bb=0;
    cin>>t>>a>>b;

    cin>>s;
    for(int i=0; i<t; i++)
    {

        if(s[i]=='a'&& aa+bb<a+b)
        {
        cout<<"Yes"<<endl;
        aa++;
        }
        else if(s[i]=='b' && aa+bb<a+b && bb<b)
        {
            cout<<"Yes"<<endl;
            bb++;

        }
        else
        {
            cout<<"No"<<endl;
        }

    }
    return 0;
}
