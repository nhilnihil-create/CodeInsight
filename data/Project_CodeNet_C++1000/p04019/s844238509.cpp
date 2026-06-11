#include<bits/stdc++.h>
using namespace std;

string str;

int main(){
  cin >> str;
  int n=0,e=0,w=0,s=0;

  for(int i=0;i<str.length();i++){
    switch(str[i]){
    case 'N':
      n++;
      break;
    case 'E':
      e++;
      break;
    case 'W':
      w++;
      break;
    case 'S':
      s++;
      break;
    }
  }

  if(n==0 && s==0 || n>0 && s>0)
    if(e==0 && w==0 || e>0 && w>0)
      cout << "Yes" << endl;
    else cout << "No" << endl;
  else cout << "No" << endl;
}