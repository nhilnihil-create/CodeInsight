#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  ll x,a,b;
  cin >> x >> a >> b;
  int c = b-a;
  if(c <= 0){
    puts("delicious");
  }
  else if(x >= c){
    puts("safe");
  }
  else{
    puts("dangerous");
  }
  return 0;
}
