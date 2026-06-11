#include <bits/stdc++.h>
using namespace std;

int f(int a,int b){
  if(to_string(a).size()>to_string(b).size())	return to_string(a).size();
  return to_string(b).size();
}

int main() {
  long int n;
  cin >> n;
  
  int ans=f(1,n);
  for(long int i=2;i*i<=n;i++){
    if(n%i==0){
      if(ans>f(i,n/i)){
      ans=f(i,n/i);
    }
    }
  }
   cout << ans;   
}