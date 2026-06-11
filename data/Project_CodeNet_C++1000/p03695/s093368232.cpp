#include <bits/stdc++.h>
using namespace std;
int main() {
  int r[9]={0},n,a,c=0; cin>>n;
  for(int i=0;i<n;i++){
    cin>>a;
    if(a/400<8) r[a/400]++;
    else r[8]++;
  }
  for(int i=0;i<8;i++) if(r[i]) c++;
  if(c) cout<<c<<" "<<c+r[8]<<endl;
  else cout<<1<<" "<<r[8]<<endl;
}