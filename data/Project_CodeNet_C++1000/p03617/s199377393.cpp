#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t q,h,s,d,n;
  cin >> q >> h >> s >> d >> n;
  int64_t iti=0,ni=0;
  if(q*2<h&&q*4<s){
    iti=q*4;
  }else if(h*2<s){
    iti=h*2;
  }else{
    iti=s;
  }
  if(iti*2<d){
    ni=iti*2;
  }else{
    ni=d;
  }
  int64_t ans=0;
  ans+=(n/2)*ni;
  ans+=(n%2)*iti;
  cout << ans << endl;
  return 0;
}