#include <bits/stdc++.h>
using namespace std;


long kei(int n,vector<int> &moji){
  int m= moji.size();
  if(n == m-1)
    return moji.at(n);
  int x=0;
  for(int i=0;i<m-n-1;i++){
    x *=2;
    x += moji.at(n) * pow(10,i);
  }
  return moji.at(n)*pow(10,m-n-1)+x+kei(n+1,moji)*2;
}

int main(){
  string str;
  cin >> str;
  vector<int>moji(str.size());
  for(int i=0;i< str.size();i++){
    moji.at(i)= str.at(i)-48;
  }
  cout << kei(0,moji) << endl;
}
  