#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  string S;
  cin >> S;
  
  ll Sum = 0, sum = 0;
  for(int i = 0; i < (1 << 9); i++){
    bitset<9> op(i);
    int opc = 0;
    sum = S.at(opc) - 48;
    
    for(int j = 0; j < S.size() - 1; j++){
      if(op.test(j)){
        Sum += sum;
        opc++;
        sum = S.at(opc) - 48;
      }
      else {
        sum *= 10;
        opc++;
        sum += S.at(opc) - 48;
      }
    }
    Sum += sum;
    sum = 0;
    if(i == pow(2, S.size() - 1) - 1){
      cout << Sum << endl;
      return 0;
    }
  }
}