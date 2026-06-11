#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int a=0;
    int z=0;
    for(int i=0;i<=n;i++)
    if(s[i]=='A')
    {
    a=i;
    break;
    }
    for(int i=n-1;n>=i;i--)
    if(s[i]=='Z')
    {
    z=i;
    break;
    }
    cout<<(z-a)+1<<endl;
    return 0;
}
 
 