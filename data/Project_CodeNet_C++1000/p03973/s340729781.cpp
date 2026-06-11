#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using lli = long long int;


int main(){
  int n;
  std::cin >> n;
  vector<lli> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  lli ans = a[0] - 1, price = 2;
  a[0] = 1;
  for (int i = 1; i < n; i++) {
    if(a[i] < price)continue;
    if(a[i] == price){
      price++;
    }else{
      ans += a[i]/price - (a[i]%price == 0);
      a[i] = price;
    }
    // for (int j = 0; j < n; j++) {
    //   std::cout << a[j] << " ";
    // }
    // std::cout << std::endl;
    // std::cout << price << " " << ans<< std::endl;
  }
  std::cout << ans << std::endl;
  return 0;
}
