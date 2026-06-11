#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    long long n,l,i;
    string s[2000];
    cin>>n>>l;
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    sort(s+1,s+1+n);
    for(i=1;i<=n;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}