#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,a,b,c;
  cin>>x>>a>>b;
  c=b-a;
  if(c>x) cout<<"dangerous"<<endl;
  else if(c>0) cout<<"safe"<<endl;
  else cout<<"delicious"<<endl;
}
  