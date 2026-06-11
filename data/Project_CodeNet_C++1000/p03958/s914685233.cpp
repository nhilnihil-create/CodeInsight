#include<iostream>
#include<vector>
#include<algorithm>

int main(){
  	int k,t;
  	std::cin >> k >> t;
  	std::vector<int> a(t);
  	for(auto&e : a){
      	std::cin >> e;
    }
  	std::sort(a.begin(), a.end());
  	int sum = 0;
  	int ans = 0;
  	for(auto&e : a){
      	ans = std::max(std::max(ans-e, 0), e-(sum+1));
      	sum += e;
    }
  	std::cout << ans << "\n";
  	return 0;
}