#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  string S;
  cin >> N >> A >> B >> S;
  int count=0,globalcount=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='a'){
      if(count<A+B){
        cout << "Yes" << endl;
        count++;
      }
      else{
        cout << "No" << endl;
      }
    }
    else if(S.at(i)=='b'){
      if(count<A+B && globalcount<B){
        cout << "Yes" << endl;
        count++;
        globalcount++;
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