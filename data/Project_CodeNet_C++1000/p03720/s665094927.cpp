#include <iostream>
#include <vector>

int main(void){
  int n, m, p;
  std::cin >> n >> m;
  std::vector<int> road(n);
  for(int i=0; i<m*2; i++){
    std::cin >> p;
    road.at(p-1)++;
  }
  for(int i=0; i<n; i++) std::cout << road.at(i) << std::endl;
  return 0;
}