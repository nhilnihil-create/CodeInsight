#include <bits/stdc++.h>
using namespace std;
//最大公約数
long long GCD(long long a, long long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(GCD(b, a%b));
   }
}

//最小公倍数
long long LCM(long long a, long long b)
{
   return a/(GCD(a,b))*b;
}
int main() {
  long long N;
  cin >> N;
  long long ans;
  cin >> ans;
  for(long long i=0; i<N-1; i++){
    long long a;
    cin >> a;
    ans = LCM(ans,a);
  }
  cout << ans << endl;
}
