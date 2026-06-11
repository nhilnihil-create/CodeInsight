#include <iostream>
using namespace std;
int main(){
  int N;cin>>N;
  int sm = 0;
  int dai;
  for(int i = 1; N >= i; i++){
    sm+=i;
    if(sm > N){
      dai=i;break;
    }
  }
  for(int i = 1; dai >= i; i++){
    if(sm - N != i)cout << i << endl;
  }
}