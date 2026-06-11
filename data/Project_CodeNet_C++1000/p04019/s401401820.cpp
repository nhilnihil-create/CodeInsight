#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
  string s;
  cin >> s;
  int a[4]={0};
  for(int i = 0; i< s.size(); i++){
    if(s.at(i) == 'N'){
      a[0]++;
    }
    else if(s.at(i) == 'S'){
      a[1] ++;
    }
    else if(s.at(i) == 'W'){
      a[2]++;
    }
    else{
      a[3]++;
    }
  }
  if(a[0]!= 0 && a[1] == 0 || a[0]== 0 &&a[1] != 0){
    cout << "No" << endl;
  }
  else if(a[2]!= 0 && a[3] == 0 || a[2]== 0 &&a[3] != 0){
    cout << "No" << endl;
  }
  else{
    cout  << "Yes" << endl;
  }
}