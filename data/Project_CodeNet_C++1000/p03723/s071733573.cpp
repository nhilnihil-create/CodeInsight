#include <bits/stdc++.h>
using namespace std;

int64_t solve(int a, int b, int c){
  if(a%2 != 0 || b%2 != 0 || c%2 != 0){
    return 0;
  }
  else{
    if(a==b && b==c){ return -1; }
    else{
      const int offset= a/2 + b/2 + c/2;
      int64_t ans= 0;
      while(a%2==0 && b%2==0 && c%2==0){
        a= offset- a/2;
        b= offset- b/2;
        c= offset- c/2;
        ans++;
      }

      return ans;
    }
  }
}

int main() {
  int a,b,c;
  cin >> a >> b >> c;

  int64_t ans= solve(a,b,c);
  
  cout << ans << endl;
}