#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,c;
  cin >> N;
  c = N / 11 * 2;
  if(N%11 != 0){
    if(N%11 > 6){
      c += 2;
    }
    else{
      c++;
    }
  }
  cout << c << endl;
}