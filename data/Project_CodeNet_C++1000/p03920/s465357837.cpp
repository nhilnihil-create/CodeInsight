#include<iostream>
using namespace std;
 
bool check(int n, int maxi){
  for (int i = maxi; i > 0; i--) {
    if(n >= i){
      n -= i;
    }
  }
  return (n == 0);
}
 
int main(){
  int n;
  std::cin >> n;
  int l = 0, r = n, mid = (r + l)/2;
  while(r - l > 1){
    if(check(n, mid)){
      r = mid;
    }else{
      l = mid;
    }
    mid = (l + r)/2;
  }
  for (int i = r; i > 0; i--) {
    if(n >= i){
      std::cout << i << std::endl;
      n -= i;
    }
  }
  return 0;
}