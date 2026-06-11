#include <bits/stdc++.h>
using namespace std;

int main()
{
  int w,a,b;
  cin>>w>>a>>b;
    if(a>b)
        cout<<a-(b+w);
    else if(a<b&&b<=(a+w)|| a==b)
        cout<<0;
    else cout<<b-(a+w);
    return 0;

}
