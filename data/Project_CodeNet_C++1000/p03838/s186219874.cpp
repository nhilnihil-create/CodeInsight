#include <bits/stdc++.h>
using namespace std;
//解説AC
int main() {
  int x,y;
  cin >>x>>y;
  int kotae=INT_MAX;
  if(x<=y)kotae=min(kotae,y-x);
  if(-x<=y)kotae=min(kotae,x+y+1);
  if(x<=-y)kotae=min(kotae,-x-y+1);
  if(-x<=-y)kotae=min(kotae,x-y+2);
  cout<<kotae<<endl;
  return 0;
}
 