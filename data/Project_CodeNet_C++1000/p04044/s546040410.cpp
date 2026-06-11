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
  int N,L;
  cin >> N >> L;

  vector<vector<string>> s(N,vector<string>(L));

  REP(i,N){
    cin >> s[i][0];
  }

  sort(s.begin(),s.end());

  REP(i,N){
    cout << s[i][0];
  }
  cout << endl;
  return 0;
}