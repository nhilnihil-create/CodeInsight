#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    int n;
    cin>>n;
    int ob=0,cb=0;
   string str;
   cin>>str;
    for(int i=0;i<n;i++)
    {
        char c=str[i];
       if(c==')')
        {
            if(ob)ob--;
            else
            cb++;
        }
        if(c=='(')
        ob++;
    }
    cout<<string(cb,'(');
    cout<<str;
    cout<<string(ob,')')<<endl;
}