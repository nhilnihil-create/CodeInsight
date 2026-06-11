#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,i,j;
    while(cin>>a>>b)
    {
        string s[1001];
        int c[1001];
        for(i=0;i<a;i++)
            cin>>s[i];

        sort(s+0,s+a);

        for(j=0;j<a;j++)
            cout<<s[j];
            cout<<endl;
    }
    return 0;
}
