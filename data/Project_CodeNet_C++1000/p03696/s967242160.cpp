#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;cin >> N;
  string S;cin >> S;
  int height=0,min_h=0;
  for(int i=0;i<N;i++){
    if(S[i]=='('){
      height ++;
    }else{
      height --;
    }
    min_h = min(min_h,height);
  }
  min_h = -min_h;
  for(int i=0;i<min_h;i++){
    cout << "(";
  }
  cout << S;
  for(int i=0;i<height+min_h;i++){
    cout << ")";
  }
  cout << endl;
}