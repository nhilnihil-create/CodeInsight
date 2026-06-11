#include<bits/stdc++.h>
using namespace  std;

int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
 
  
  for(int i=0;i<N; i++){
    cin >> vec.at(i);
  }
  int count = 0, next = 1;
  
 for(int j=0; j<N; j++){
   count++;
   next = vec.at(next-1);
   if(next == 2)break; 
 }
  if(next != 2){count = -1;}
  
  cout << count << endl;
}