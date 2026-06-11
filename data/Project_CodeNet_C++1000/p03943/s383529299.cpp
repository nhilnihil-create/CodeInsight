#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
int main()
{
   int a[4];
   cin>>a[0]>>a[1]>>a[2];
   sort(a,a+3);
   if(a[0]+a[1]==a[2])
      cout<<"Yes";
   else
      cout<<"No";
   cout<<nl;
    return 0;
}
