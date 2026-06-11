#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>
#include <fstream>
#include <map>
using namespace std;
typedef long long ll;
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)


int main(){
  vector<ll> A{0,0,0};
  bool flag = false;
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(),A.end());
  REP(i,3){
    if(A[i]%2==0){
      flag = true;
      break;
    }
  }
  if(flag){
    cout << 0 << endl;
    return 0;
  }
  else{
    ll result = A[0]*A[1];
    cout << result << endl;
    return 0;
  }
}