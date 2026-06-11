#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll a,b,x,temp;
    cin>>a>>b>>x;
    temp=a/x;
    if(a%x!=0)
    {
        a=(temp+1);
    }
    else
        a=temp;
   // cout<<a<<endl;
    b=b/x;
      cout<<b-a+1<<endl;
    return 0;
    }
