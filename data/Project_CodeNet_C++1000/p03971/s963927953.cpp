#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  int na=0;
  int nb=0;
  for(int i=0;i<N;i++){
    if(S.at(i)=='a'){
      if(na+nb<A+B){
        cout << "Yes" << endl;
        na++;
      }else{
        cout << "No" << endl;
      }
    }else if(S.at(i)=='b'){
      if((na+nb<A+B)&&(nb+1<=B)){
        cout << "Yes" << endl;
        nb++;
      }else{
        cout << "No" << endl;
      }
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}
