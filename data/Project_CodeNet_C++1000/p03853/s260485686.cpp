#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
string s[1000];
int n,m;
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        for(int j=0;j<n;j++)
        {
            cout<<s[j]<<endl;
            cout<<s[j]<<endl;
        }
    }
    return 0;
}
