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
  long long int n;
  string s;
  cin>>n>>s;
  long long int right=0;
  long long int left=0;
  for(long long int i=0; i<n; i++){
    if(s[i]=='('){
      left++;
    }else{
      if(left!=0){
        left--;
      }else{
        right++;
      }
    }
  }
  string L="",R="";
  for(long long int i=0; i<right; i++){
    L+="(";
  }
  for(long long int i=0; i<left; i++){
    R+=")";
  }
  string ans=L+s+R;
  cout<<ans<<endl;

}