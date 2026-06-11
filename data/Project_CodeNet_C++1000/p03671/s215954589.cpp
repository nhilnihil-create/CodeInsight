#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)

int a,b,c;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>a>>b>>c;
    cout<<(a+b+c)-max(a,max(b,c));
}


