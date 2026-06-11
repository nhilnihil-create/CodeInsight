#include <bits/stdc++.h>

using namespace std;

int main(){
  string x;
  cin >> x;
  int minus=0;
  int s_cnt=0, t_cnt=0;
  for(int i=0;i<x.length();i++){
    if(x[i]=='T'){
      while(i<x.length() && x[i]=='T'){
        t_cnt++;
        i++;
      }
      minus += 2*min(s_cnt, t_cnt);
      s_cnt=s_cnt - min(s_cnt, t_cnt)+1;t_cnt=0;
    }
    else{
      s_cnt++;
    }
  }
  cout << x.length() - minus  << endl;
}

