#include<bits/stdc++.h>
using namespace std;
int c[30];
int main()
{
    string s;
    cin>>s;
    int i,f=0;
    for(i=0;i<s.size();i++)
        c[s[i]-97]++;
    for(int j=0;j<26;j++)
    {
        if(c[j]%2!=0)
        {
            f=1;
            break;
        }
    }
    if(f==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}
