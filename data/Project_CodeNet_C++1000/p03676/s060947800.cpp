#include <iostream>
#include <vector>
#include <map>
#define llint long long int

#define SIZE 100002
#define MOD 1000000007
llint fac[SIZE] = {};
llint finv[SIZE] = {};

llint power(llint base, llint pow){
  llint result = 1;
  while(pow > 1){
    if(pow%2 == 1){
      result = (result * base)%MOD;
    }
    pow/=2;
    base = (base*base)%MOD;
  }
  return (result * base)%MOD;
}

void COMBinit(){
  for(int i=0; i<SIZE; i++){
    if(i<2) fac[i] = 1;
    else fac[i] = (fac[i-1]*i)%MOD;
  }

  finv[SIZE-1] = power(fac[SIZE-1], MOD-2);
  for(int i=SIZE-2; i>=0; i--){
    if(i==0) finv[i] = 1;
    else finv[i] = (finv[i+1]*(i+1))%MOD;
  }
}
llint comb(int a, int b){
  if(a < b) return 0;
  return ((fac[a] * finv[a-b])%MOD * finv[b])%MOD;
}

int main(void){

  int n;
  std::cin >> n;

  COMBinit();

  std::vector<int> a(n+1);
  std::map<int, int> count;
  for(int i=0; i<a.size(); i++){
    std::cin >> a[i];
    if(count.find(a[i]) == count.end()) count[a[i]] = 0;
    count[a[i]]++;
  } //sum^N_k O(logk) = O(nlogn)

  int doubled = -1;
  for(const auto& elem: count){
    if(elem.second == 2){
      doubled = elem.first;
      break;
    } 
  } // O(n)

  int doubled_first = -1;
  int doubled_second = -1;
  for(int i=0; i<a.size(); i++){
    if(a[i] == doubled){
      if(doubled_first==-1) doubled_first = i;
      else                  doubled_second = i;
    }
  } //O(n)

  int count_left = doubled_first;
  int count_right = a.size() - doubled_second - 1;
  for(int k=1; k<=n+1; k++){
    llint ret = (comb(n+1, k) - comb(count_left+count_right, k-1) + MOD)%MOD;
    //std::cout << n+1 << " " << k << " " << count_left+count_right << " " << k-1 << " " << std::endl;
    std::cout << ret << std::endl;
  }
  
  
}
