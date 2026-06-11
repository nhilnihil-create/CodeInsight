#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
map <int ,int> mpa,mpb;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin >> N;
  if(N==1){
    cout << 1 << endl;
    return 0;
  }
  if(N==2){
    cout << 2 << endl;
    return 0;
  }
  ll n=0;
  ll s=0;
  for(int i=1;i<N;i++){
    s=i*(i+1)/2;
    if(s>=N){
      n=i;
      break;
    }
  }
  ll c=s-N;
  for(int i=1;i<=n;i++){
    if(i==c) continue;
    cout << i << endl;
  }
  return 0;
}