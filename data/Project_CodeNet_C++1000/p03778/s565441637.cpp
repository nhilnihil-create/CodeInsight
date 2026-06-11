#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int w,a,b;
  cin>>w>>a>>b;

  if((b+w-a<=2*w && b>a) || ((a+w-b<=2*w) && b<a) || (b==a))
    cout<<0<<endl;
  else
    cout<<min(abs(a+w-b),abs(b+w-a))<<endl;

	return 0;
}