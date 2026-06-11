#include <bits/stdc++.h>
using namespace std;

int main(){
  using ll= long long int;
  ll Ns,Nc;
  cin >> Ns >> Nc;
  
  ll diff= Nc- 2*Ns;
  if(diff >= 0){
    cout << Ns+ diff/4 << endl;
  }
  else{
    cout << Nc/2 << endl;
  }
}