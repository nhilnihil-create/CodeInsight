#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long int x,ans;
  cin>>x;
  if(x%11==0)
  {
    cout<<(x/11) * 2;
  }
  else if(x%11 > 6)
    cout<<((x/11)*2) + 2;
  else
    cout<<((x/11)*2) + 1;
  
  return 0;
}
