#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  int s_cnt=0,t_cnt=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='T'){
      if(s_cnt>0)s_cnt--;
      else t_cnt++;
    }else s_cnt++;
  }
  cout<<t_cnt*2<<endl;
  return 0;
}