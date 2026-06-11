#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
   int t;
          t=1;
          while(t--)
          {
            ll a,b,c;
            cin>>a>>b>>c;
            if(a+b == c || a+c == b || b+c == a)
              cout<<"Yes";
            else
              cout<<"No";
          }
  return 0;
}
