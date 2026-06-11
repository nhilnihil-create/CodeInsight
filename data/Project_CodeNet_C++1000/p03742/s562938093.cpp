#include <bits/stdc++.h>
using namespace std;
int main(){
  long long x,y; cin>>x>>y;
  if (x<y) swap(x,y);
  if (x-y>1) puts("Alice");
  else puts("Brown");
  return 0;
}
