#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;
  int N=S.size();
  int count=0;
  for(int i=N-1;i>=0;i){
    if(i<=3){
      cout << "NO" << endl;
      return 0;
    }
    string T="";
    for(int j=0;j<5;j++){
      T=S[i-j]+T;
    }
    i-=5;
    if(T=="dream" || T=="erase"){
      continue;
    }
    T=S[i]+T;
    i-=1;
    if(T=="eraser"){
      continue;
    }
    T=S[i]+T;
    i-=1;
    if(T=="dreamer"){
      continue;
    }
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
}