#include<iomanip>
#include <string>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <stdio.h>
#include <numeric>
#include<math.h>
#include <ctype.h>
#include <algorithm> // sort
#include <map> // pair
using namespace std;
#define nin(n) int n; cin >> n;
#define kin(k) int k; cin >> k;
const int INF = 1001001001;
int main(){
  bool ans=true;
  int n;cin >> n;
  int a;
  int b=0;
  int acount=0;int bcount=0;
  cin >> a;acount++;
  int tmp;
  int i=1;
  while(b==0&&i<n){
    cin >> tmp;
    if(tmp==a){ acount++;
    }
    else{
      b=tmp;
      bcount++;
    }
    i++;
  }
  if(b!=0){  
    if(abs(a-b)>1) ans=false;
  }
  while(i<n){
    cin >> tmp;
    if(tmp==a){
      acount++;
    }
    else if(tmp==b){
      bcount++;
    }
    else{
      ans=false;
    }
  i++;
  }
  if(b>a){
    tmp=b;
    b=a;a=tmp;
    tmp=bcount;
    bcount=acount;acount=tmp;
  }
  if(ans){
    if(b==0){
      if(a!=n-1){
        if(n<2*a){
          ans=false;
        }
      }
    }
    else if(bcount>b||bcount<a*2-n){
      ans=false;
    }
  }
  if(ans) cout << "Yes";
  else cout << "No";
}