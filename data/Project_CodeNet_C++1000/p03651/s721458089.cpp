#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
 
long long gcd(long long a, long long b){
  	long long M = std::max(a, b);
  	long long m = std::min(a, b);
  	if(M%m==0) return m;
  	return gcd(M%m, m);
}
 
int main(){
  	int n;
  	long long k;
  	std::cin >> n >> k;
  	std::vector<long long> a(n);
  	
  	bool abs1 = false;
  	std::cin >> a.at(0);
  	long long max = a.at(0);
  	long long prev = a.at(0);
  	if(a.at(0)==k){
         std::cout << "POSSIBLE" << "\n";
         return 0;
    }
  	for(int i=1;i<n;i++){
      	auto& e = a.at(i);
      	std::cin >> e;
      	long long g = gcd(prev, e);
      	if(k%g==0){
          	abs1=true;
        }
      	if(e==k){
          	std::cout << "POSSIBLE" << "\n";
          	return 0;
        }
      	if(g==1){
          	abs1=true;
        }
      	max = std::max(max, e);
      	prev = e;
    }
  	if(max > k && abs1){
      	std::cout << "POSSIBLE" << "\n";
    }else{
      	std::cout << "IMPOSSIBLE" << "\n";
    }
  	return 0;
}