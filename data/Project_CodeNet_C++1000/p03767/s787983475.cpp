#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int
int main()
{
 int n;
  cin>>n;
  ll a[3*n];
  for(int i=0;i<3*n;i++)
    cin>>a[i];
  sort(a,a+3*n);
  ll ans=0;
  for(int i=n;i<3*n;i=i+2)
    ans+=a[i];
  cout<<ans;
  return 0;
}