#include <iostream>
#include <string>
using namespace std;

int main(){
  int N;
  string S;
  cin >> N;
  cin >> S;
  int max=0;
  int x=0;
  for(auto itr=S.begin();itr!=S.end();itr++){
    if(*itr=='I'){
      ++x;
    }else{
      --x;
    }
    if(x>=max) max=x;
  }
  cout << max << endl;
  
}