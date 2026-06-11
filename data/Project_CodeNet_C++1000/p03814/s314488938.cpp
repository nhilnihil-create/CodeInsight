#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int N = s.size();
  
  int counta = 0;
  for(int i = 0; i < N; i++){
    if(s.at(i) == 'A'){
      counta = i;
      break;
    }
  }
  
  int countz = 0;
  for(int i = N-1; i >= 0; i--){
    if(s.at(i) == 'Z'){
      countz = i;
      break;
    }
  }
  
  cout << countz - counta + 1 << endl;
  
}