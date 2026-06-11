#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a,b;
int main()
{
    cin >> a;b=a;
    reverse(a.begin(),a.end());
    for(unsigned i=0;i<a.size();i++)
    {
        if(a[i]=='b') a[i]='d';
        else if(a[i]=='d') a[i]='b';
        else if(a[i]=='p') a[i]='q';
        else if(a[i]=='q') a[i]='p';
    }
    bool(a==b)?cout << "Yes\n":cout << "No\n";
    return 0;
}