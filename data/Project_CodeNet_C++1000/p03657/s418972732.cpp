#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

int n,m;
int main()
{
   

    cin>>n>>m;
    if(n%3==0 || m%3==0 || (n+m)%3==0)
        cout<<"Possible";
    else
        cout<<"Impossible";
}


