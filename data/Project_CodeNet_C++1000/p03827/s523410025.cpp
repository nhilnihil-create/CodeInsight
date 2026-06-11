#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  string S;
  int x=0,maxi;
  cin >> S;
  maxi=0;
  for(int i=0;i<S.size();i++){
    if(S[i]=='I'){
      x++;
    }else if(S[i]=='D'){
      x--;
    }
    maxi = max(maxi,x);
  }
  cout << maxi << endl;
}