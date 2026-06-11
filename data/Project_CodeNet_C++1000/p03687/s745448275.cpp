#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
  string s;
  cin>>s;
  long long int ans=1000000000000;
  for(long long int i=0; i<s.size(); i++){
    char use=s[i];
    long long int pre=0;
    string t=s;
    while(true){
      bool all=true;
      string hoge;
      for(long long int j=0; j<t.size(); j++){
        if(t[j]!=use) all=false;
        if(j==t.size()-1) continue;
        if(t[j+1]==use){
          hoge+=use;
        }else if(t[j]==use){
          hoge+=use;
        }else{
          hoge+=t[j];
        }
      }
      t=hoge;
      if(all){
        break;
      }else{
        pre++;
      }
    }
    ans=min(ans,pre);
  }
  cout<<ans<<endl;
}