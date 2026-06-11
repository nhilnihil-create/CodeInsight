#include <bits/stdc++.h>
#define re register
using namespace std;
string a,b;
int main() 
{
    getline(cin,a);
    b=a;
    reverse(a.begin(),a.end());
    for ( re int i=0;i<a.length();i++ ) 
    {
        if(a[i]=='b') a[i]='d';
        else if(a[i]=='d') a[i]='b';
        else if(a[i]=='p') a[i]='q';
        else if(a[i]=='q') a[i]='p';
    }
    if(a==b) return printf("Yes\n"),0;
    else printf("No\n"),0;
    return 0;
}
        