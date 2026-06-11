#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,i;
    while(cin>>a>>b)
    {
        string s[1001];
        for(i=0;i<a;i++)
        {
            cin>>s[i];
        }
        sort(s+0,s+a);
        for(int j=0;j<a;j++)
            cout<<s[j];
    }
    return 0;
}
