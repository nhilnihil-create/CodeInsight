#include<bits/stdc++.h>
using namespace std;

int main(){
  long long x;
  cin>>x;
  long long div = x/11*2;
  if(x%11==0) cout<<div;
  else if(x%11<=6) cout<<div+1;
  else cout<<div+2;
}