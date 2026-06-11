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
  long long int ans=s.size();
  long long int nows=0;
  for(long long int i=0; i<s.size(); i++){
    if(s[i]=='S'){
      nows++;
    }
    if(s[i]=='T'){
      if(nows>0){
        nows--;
        ans-=2;
      }
    }
  }
  cout<<ans<<endl;
}