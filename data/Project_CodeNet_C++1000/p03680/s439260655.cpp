#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,c,p,i;
  cin>>n;
  vector<int> a(n);
  for (i=0;i<n;i++) {
    cin>>a.at(i);
  }
  p=1;
  c=1;
  while (a.at(p-1)!=2 && c<n) {
    p=a.at(p-1);
    c++;
  }
  if (c<n) cout<<c<<endl;
  else cout<<-1<<endl;
}
