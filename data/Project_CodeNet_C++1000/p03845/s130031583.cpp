#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> vec(N);
  
  for(int i=0; i<N;i++){
    cin >> vec.at(i);
  }
  
  int count;
  
  
  int M;
  cin >> M;
  
  
  
  
  for(int j=0; j<M; j++){
    
    count=0;
     for(int i=0; i<N; i++){
    count+=vec.at(i);
  }
  
   
    
    int P,X;
    cin >> P>> X;
    
    count -= vec.at(P-1);
    count += X;
    cout << count<< endl;
  }
    
    
}