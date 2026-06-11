#include <bits/stdc++.h>
using namespace std;

int main() {
  long long deadline,konyu,eat;
  cin >> deadline >> konyu >> eat;
  
  if(konyu - eat >= 0){
    cout << "delicious";
  }else if(deadline - (eat - konyu) >= 0){
    cout << "safe";
  }else{
    cout << "dangerous";
  }
}
