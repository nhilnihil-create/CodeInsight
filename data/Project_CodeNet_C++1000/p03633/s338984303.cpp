#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

long long lcm(long long a, long long b)
{
   return a  / gcd(a, b)*b;
}
int main() {
  int n; cin >>n;
  vector<long long>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  long long kotae=1;
  for(int i=0;i<n;i++){
    kotae=lcm(kotae,a[i]);
  }
  cout<<kotae<<endl;
  return 0;
}