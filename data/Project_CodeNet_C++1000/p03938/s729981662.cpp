#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  map<int,int> mp;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
    mp[vec.at(i)] = i+1;
  }
  vector<int> A(N,1);
  vector<int> B(N,1);
  for(int i=1; i<N; i++){
    A.at(i) = A.at(i-1) + mp[i+1];
  }
  for(int i=N-2; i>=0; i--){
    B.at(i) = B.at(i+1) + mp[i+1];
  }
  for(int i=0; i<N; i++){
    cout <<  A.at(i);
    if(i != N-1){
      cout << " ";
    }
    else{
      cout << endl;
    }
  }
  for(int i=0; i<N; i++){
    cout <<  B.at(i);
    if(i != N-1){
      cout << " ";
    }
    else{
      cout << endl;
    }
  }
}     