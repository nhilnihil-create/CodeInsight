#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c;cin>>a>>b>>c;
  if(a==0&&c!=1)cout<<b/c+1<<endl;
  else cout<<b/c-(a-1)/c<<endl;
}