#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int pos=0, neg=0;
  for(int i=0; i<n; i++){
    if(s[i]=='('){
      pos++;
    }else{
      if(pos>0) pos--;
      else neg++;
    }
  }
  for(int i=0; i<neg; i++){
    cout <<"(";
  }
  cout << s;
  for(int i=0; i<pos; i++){
    cout <<")";
  }
  cout << endl;
  return 0;
}
