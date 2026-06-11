#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,a,b;
  cin>>n>>a>>b;
  long long shou=a+b+(n-2)*a;
  long long dai=a+b+(n-2)*b;
  if(n==1){
    if(a!=b)cout<<0<<endl;
    else cout<<1<<endl;
  }else if(n==2)cout<<a+b<<endl;
  else cout<<max((long long) 0,dai-shou+1)<<endl;
  return 0;
}
