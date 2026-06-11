#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int a,b,c;
    cin>>a>>b>>c;
    if(a==b && b==c)
        cout<<1<<"\n";
    else if(a==b || a==c || b==c)
        cout<<2<<"\n";
    else cout<<3<<"\n";
}
