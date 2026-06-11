#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,countA=0,countB=0;//Aはそこまでの予選通過人数、Bは買いが期の学生の中の順位
  string S;
  cin >> N >> A >> B >> S;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='a'){
      if(countA<A+B){
        countA++;
        cout << "Yes" << endl;
      }
      else{
        cout << "No" << endl;
      }
    }
    else if(S.at(i)=='b'){
      countB++;
      if(countA<A+B && countB<=B){
        cout << "Yes" << endl;
        countA++;
      }
      else{
        cout << "No" << endl;
      }
    }
    else{
      cout << "No" << endl;
    }
  }
}