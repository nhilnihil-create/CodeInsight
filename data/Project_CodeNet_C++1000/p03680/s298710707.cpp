#include <iostream>
#include <vector>

int main(void){
  int n, p, count;
  std::cin >> n;
  std::vector<int> a(n);
  for(int i=0; i<n; i++) std::cin >> a.at(i);
  
  p = a.at(0);
  count = 1;
  for(int i=0; i<n; i++){
    if(p == 2){
      std::cout << count << std::endl;
      return 0;
    }
    p = a.at(p-1);
    count++;
  }
  std::cout << -1 << std::endl;
  return 0;
}