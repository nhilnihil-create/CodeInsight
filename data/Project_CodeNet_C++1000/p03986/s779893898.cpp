#include<iostream>
using namespace std;


int main(){
  string x;
  cin >> x;
  int cnt = 0;
  for(int i=0;i<x.size();++i){
    if(x[i] == 'T' && cnt){
      cnt -= 1;
    }else if(x[i] == 'S'){
      cnt += 1;
    }
  }
  cout << 2 * cnt << endl;
}
