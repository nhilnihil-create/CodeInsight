#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  long long count=0;
  cin >> N;
  vector<int>vec(N);
  for(int i=0;i<N;i++){
    cin >> vec.at(i);
  }
  
  
  for(int i=0;i<N;i++){
    if(i==N-1){
      count+= vec.at(i)/2;
    }
    else if(vec.at(i)%2==1){
      count += vec.at(i)/2;
      if(vec.at(i+1)>0){
        vec.at(i+1)--;
        count++;
      }
    }
    else{
      count += vec.at(i)/2;
    }
  }
  
  cout << count <<endl;
}
