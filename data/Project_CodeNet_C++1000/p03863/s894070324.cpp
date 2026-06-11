#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string st;
int l;
int main()
{
    cin>>st;
    l=max(st.size(),st.length());
    if(st[0]==st[l-1])
    {
        if(l%2==0)cout<<"First"<<endl;
           else cout<<"Second"<<endl;
    }
    else
    {
        if(l%2==0)cout<<"Second"<<endl;
          else cout<<"First"<<endl;
    }
    return 0;
}