#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[10001],s=0;
    cin>>a>>b;
    for(int i=0;i<a;i++)
    {
        cin>>c[i];
    }
    sort(c,c+a);
    reverse(c,c+a);
    for(int i=0;i<b;i++)
    {
        s=s+c[i];
    }
    cout<<s<<endl;
}
