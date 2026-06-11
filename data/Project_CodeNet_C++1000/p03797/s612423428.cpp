#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
  ll n,m,res;
  cin >> n >> m;
  if(n>=m/2)
    res=m/2;
  else
    res=(m+2*n)/4;
  cout << res << endl;
  return 0;
}