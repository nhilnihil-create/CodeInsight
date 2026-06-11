#include<iostream>
using namespace std;
long long lcm(long long m, long long n)
{
  long long mm=m,nn=n;
  while (m>0&&n>0){
    n = n % m;
    if (n>0)
      m = m % n;
  }
  if (n==0)
    return mm/m*nn;
  else
    return nn/n*mm;
}
int main()
{
  int n,i;
  long long t,res=1;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> t;
    res=lcm(res,t);
  }
  cout << res << endl;
  return 0;
}