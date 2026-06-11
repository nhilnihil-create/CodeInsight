#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

int a,b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    cin>>a>>b;
    if(a+b<=9)
        cout<<a+b;
    else
        cout<<"error";
}


