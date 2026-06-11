#include <iostream>
#include <string>

using namespace std;

int main(){
  string N;
  cin >> N;
  int pcount=0;
  for(auto &i : N){
    if(i=='p')
      pcount++;
  }
  cout << N.size()/2-pcount;
}