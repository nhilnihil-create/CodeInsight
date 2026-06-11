#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  sort(vec.begin(),vec.end());
  bool flag = true;
  int A = vec.at(0);
  int smaller = 0; 
  int bigger = 0;
  for(int i=0; i<N; i++){
    if(vec.at(i) == A){
      smaller++;
    }
    else if(vec.at(i) == A+1){
      bigger++;
    }
    else{
      flag = false;
    }
  }
  int single = 0;
  int some = 0;
  if(bigger != 0){
    single = smaller;
    some = (A+1) - smaller;
    if(some < 1){
      flag = false;
    }
    if(N < single + some*2){
      flag = false;
    }
  }
  else{
    some = A;
    if(N < single + some*2 && N != A+1){
      flag = false;
    }
  }
  if(flag){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}