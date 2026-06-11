#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin>>N;
  vector<int64_t> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  bool age;
  for(int i=1;i<N;i++){
    if(vec.at(i)==vec.at(i-1)) continue;
    else if(vec.at(i)>vec.at(i-1)){
      age=true;
      break;
    }
    else{
      age=false;
      break;
    }
  }
  int64_t kai=1;
  for(int i=1;i<N;i++){
    if(age){
      if(vec.at(i)>=vec.at(i-1)) continue;
      else{
        kai++;
        for(int j=i+1;j<N;j++){
          if(vec.at(j)==vec.at(j-1)) continue;
          else if(vec.at(j)>vec.at(j-1)){
            age=true;
            break;
          }
          else{
            age=false;
            break;
          }
        }
      }
    }
    else{
      if(vec.at(i)<=vec.at(i-1)) continue;
      else{
        kai++;
        for(int j=i+1;j<N;j++){
          if(vec.at(j)==vec.at(j-1)) continue;
          else if(vec.at(j)>vec.at(j-1)){
            age=true;
            break;
          }
          else{
            age=false;
            break;
          }
        }
      }
    }
  }
  cout<<kai<<endl;
        
    
  
}