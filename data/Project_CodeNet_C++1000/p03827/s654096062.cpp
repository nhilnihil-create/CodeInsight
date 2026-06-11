#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n,count =0,max=0;
  string s;
  cin >> n >> s;
  for(int i=0; i< n; i++){
    if( s[i] == 'I'){
      count++;
      if(max <= count) max =count;
    }else if( s[i] == 'D'){
      count--;
    }
  }
  cout << max << endl;
  return 0;
}