#include<bits/stdc++.h>
using namespace std;

bool unblc(string s,int &x,int &y){
  int n=s.size();
  x=-1;y=-1;
  for(int i=0;i<n-1;i++){
    if(s.at(i)==s.at(i+1)){
      x=i+1;y=i+2;
      return 1;
    }
  }
  for(int i=0;i<n-2;i++){
    if(s.at(i)==s.at(i+2)){
      x=i+1;y=i+3;
      return 1;
    }
  }
  return 0;
}

int main(){
  string s;
  cin >> s;
  int x,y;
  unblc(s,x,y);
  cout << x << " " << y << endl;
}