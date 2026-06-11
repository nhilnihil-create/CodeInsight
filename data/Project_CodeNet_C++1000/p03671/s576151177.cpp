#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  vector<int> x={a,b,c};
  sort(x.begin(),x.end());
  cout<<x[0]+x[1]<<endl;
}
