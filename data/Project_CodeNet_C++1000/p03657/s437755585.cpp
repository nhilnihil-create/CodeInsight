#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int a,b;
  cin >> a >> b;
  if(a%3 == 0){
    puts("Possible");
  }
  else if(b%3 == 0){
    puts("Possible");
  }
  else if((a+b)%3 == 0){
    puts("Possible");
  }
  else{
    puts("Impossible");
  }
  return 0;
}
