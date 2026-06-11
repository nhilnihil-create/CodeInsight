#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int start=max(a,c);
  int finish=min(b,d);
  cout<<max(0,finish-start)<<endl;
}
