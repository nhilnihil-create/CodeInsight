#include<string>
#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ans=0;
    int i;
    int len=s.length()-2;
    for(i=0;i<=len;i++)
    {
        if(s[i]!=s[i+1]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
