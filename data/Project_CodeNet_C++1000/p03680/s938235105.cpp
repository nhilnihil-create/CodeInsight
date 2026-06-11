#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int N;
 cin >> N ;
 vector<int> Light(N);
 
 for(int i = 0; i < N; i++){
  cin >> Light.at(i);
 }   
  int NEXT = 1;
  int check = 0;
  int kai = 1;
  
  for(int i = 0; i < N; i++){
   if(Light.at(NEXT -1) == 2){
     check = 1;
     break;
   }else{
     NEXT = Light.at(NEXT - 1);
     kai++;
   }
  }
  
  if(check == 1){
    cout << kai <<endl;
  }else{
    cout << -1 <<endl;
  }
  


}