#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,a,b;
  cin >> n >> a >> b;
  if(a>b){
    cout << 0 << endl;
  }else if(a==b){
    cout << 1 << endl;
  }else{
    if(n==1){
      cout << 0 << endl;
    }else{
      long long ans=1;
      ans=max(1ll,(b-a)*(n-2)+1);
      cout << ans << endl;
    }
  }
  return 0;
}
