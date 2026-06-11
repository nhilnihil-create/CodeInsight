#include<bits/stdc++.h>
using namespace std;
int a[27];
int main()
{
    long long int i,j,k,z,t,x,y,n;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
        a[s[i]-97]++;
    x=0;
    for(i=0;i<26;i++)
    {
        if(a[i]%2)
            x=1;
    }
    if(x)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}