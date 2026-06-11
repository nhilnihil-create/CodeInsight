#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int min;
  min = 10000;
  
  vector<int> vec(N);
  for(int i=0; i<N;i++){
    cin >> vec.at(i);
    if(vec.at(i) % 10 !=0 && vec.at(i)<min){
      min = vec.at(i);
    }
  }
  
  int count =0;
  for(int j=0;j<N;j++){
    count+= vec.at(j);
  }
  
  if(count % 10 ==0 && min != 10000){
    count -= min;
    cout << count <<endl;
  }
  
  else if (count % 10 == 0 && min == 10000){
    count = 0;
    cout <<count <<endl;
  }
  
  else {
    cout << count <<endl;
  }
      
      
      
  
  
    
}
