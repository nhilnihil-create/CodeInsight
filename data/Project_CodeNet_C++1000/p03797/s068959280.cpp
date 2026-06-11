#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,M;
  cin >> N >> M;
  if(N*2 <= M){
   cout << (N*2+M)/4 << endl;
    return 0;
  }
  cout << M/2 << endl;
}

