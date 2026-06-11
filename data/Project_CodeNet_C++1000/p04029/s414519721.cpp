#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int N;
  cin>> N;
  
 if(N%2==0){
 cout<< (N+1)*N/2;
 }
 else{
 cout<< (N+1)*(N/2)+(N+1)/2;
}
  
}
