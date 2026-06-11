#include <iostream>
#include <vector>

void output(std::vector<int> v){
  for(int i=0; i<v.size()-1; i++){
    std::cout << v[i] << " ";
  }
  std::cout << v[v.size()-1] << std::endl;
}

int main(void){
  std::vector<int> odd;
  std::vector<int> even;
  std::vector<int> A;
  int N, M;
  std::cin >> N >> M;
  
  int a;
  for(int i=0; i<M; i++){
    std::cin >> a;
    if(a%2) odd.push_back(a);
    else even.push_back(a);
  }
  
  if(odd.size() > 2){
    std::cout << "Impossible" << std::endl;
    return 0;
  }
  
  
  // create line A
  if(odd.size() >= 1){
    A.push_back(odd[0]);
  }
  for(int i=0; i<even.size(); i++){
    A.push_back(even[i]);
  }
  if(odd.size() == 2){
    A.push_back(odd[1]);
  }
  
  
  std::vector<int> B;
  
  if(A.size() == 1 && A[0] == 1){
    std::cout << 1 << std::endl
	      << 1 << std::endl
	      << 1 << std::endl;
  }else if(A.size() == 1){
    std::cout << A[0] << std::endl
	      << 2 << std::endl
	      << A[0]-1 << " " << 1 << std::endl;
  }else{
    if(A[0] != 1){
      B.push_back(A[0]-1);
    }
    for(int i=1; i<A.size()-1; i++){
      B.push_back(A[i]);
    }
    if(A.size() != 1){
      B.push_back(A[A.size()-1]+1);
    }
    
    output(A);
    std::cout << B.size() << std::endl;
    output(B);
  }
  
  
  
  
  return 0;
}