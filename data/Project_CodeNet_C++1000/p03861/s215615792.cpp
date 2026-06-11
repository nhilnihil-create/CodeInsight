#include <iostream>
using namespace std;
using ll = long long;

int main(){
  ll a, b, x;
  cin >> a >> b >> x;
  auto f = [x](ll n)->ll{
    if(n<0){
    return 0;
    }else{
    return n/x+1;
    }
  };
  cout << f(b)-f(a-1);
  return 0;
}