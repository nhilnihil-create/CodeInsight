#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b,c;
  cin >>a>>b>>c;
  long long sa=LLONG_MAX;
  sa=min(sa,abs(a/2*2*b*c-a*b*c));
  sa=min(sa,abs(b/2*2*a*c-a*b*c));
  sa=min(sa,abs(c/2*2*a*b-a*b*c));
  cout<<sa<<endl;
  return 0;
}
           
           