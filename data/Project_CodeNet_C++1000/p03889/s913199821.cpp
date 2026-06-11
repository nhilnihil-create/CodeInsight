#include <bits/stdc++.h>
using namespace std;
  
int main() {
  string S;
  cin >> S;
  string T=S;
  int s=S.size();
  int a=0;
  reverse(T.begin(),T.end());
  for(int i=0;i<s;i++){
    if(S[i]=='d' && T[i]=='b'){a+=0;}
    else if(S[i]=='b' && T[i]=='d')a+=0;
    else if(S[i]=='p' && T[i]=='q')a+=0;
    else if(S[i]=='q' && T[i]=='p')a+=0;
    else{cout << "No" << endl; return 0;}
  }
  cout << "Yes" << endl;
}