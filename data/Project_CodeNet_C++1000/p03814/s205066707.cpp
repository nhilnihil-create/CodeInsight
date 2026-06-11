#include <bits/stdc++.h>
using namespace std;

int main(){

string s;
  cin >> s;
  int a,b;
  int N = s.size();
  for(int i=0;i<N;i++){
  if(s[i]=='A'){
    a=i;
    break;
  }
  }
  for(int i=N-1;i>=0;i--){
  if(s[i]=='Z') {
    b=i;
    break;
  }
  }
  cout << b-a+1 << endl;
}
  