#include<bits/stdc++.h>
using namespace std;
int main(){
  int j,t,g;
  cin >> j >> t >> g;
  int f=0,s=0;
  if(j==5){
    f++;
  }
  else if(j==7){
    s++;
  }
  if(t==5){
    f++;
  }
  else if(t==7){
    s++;
  }
  if(g==5){
    f++;
  }
  else if(g==7){
    s++;
  }
  if(s==1&&f==2){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}