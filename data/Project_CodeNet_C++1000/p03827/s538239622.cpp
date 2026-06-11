#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int x[N+1];
  x[0] = 0;
  for(int i = 0; i< N; i++){
    if(S.at(i) == 'I'){
      x[i+1] = x[i]+1;
    }
    else{
      x[i+1] = x[i]-1;
    }
  }
  sort(x,x+N+1);
  cout << x[N] << endl;
}