#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

int a,b,c,d;
int main()
{
    
    cin>>a>>b>>c>>d;
    if(a*b>=c*d)
        cout<<a*b;
    else
        cout<<c*d;
}


