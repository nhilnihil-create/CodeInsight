#include<iostream>
#include<algorithm>

int main(){
  	long long N,M,m;
  	std::cin >> N >> m >> M;
  	if(m>M || (N==1 && m!=M)){
      	std::cout << "0\n";
      	return 0;
    }
  	std::cout << 1ll+std::max((M-m)*(N-2),0ll) << "\n";
  	return 0;
}