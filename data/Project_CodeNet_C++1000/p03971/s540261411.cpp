#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  string str;
  cin >> str;
  
  int foreign=0;
  int pass = 0;
  for(int i=0;i<N;i++){
    if(str.at(i)=='c'){
      cout << "No" << endl;
    }else if(str.at(i)=='a'){
      if(pass < A+B){
        cout << "Yes" << endl;
        pass++;
      }else{
        cout << "No" << endl;
      }
    }else{
      if(pass < A+B && foreign < B){
        cout << "Yes" <<endl;
        pass++;
        foreign++;
      }else{
        cout << "No" << endl;
      }

    }
  }
}