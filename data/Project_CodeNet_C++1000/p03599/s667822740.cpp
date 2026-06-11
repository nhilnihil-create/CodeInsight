#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>
int max_sugar_sub(int x, int c, int d, int e, int f) {
  int cnt = -1;
  
  for (int i = 0; i <= e*x/c; i++) {
    for (int j = 0; j <= e*x/d; j++) {
      int sugar = i*c + j*d;
      if (sugar <= e*x && 100*x + sugar <= f) {
        cnt = max(cnt, sugar);
      }
    }
  }
  return cnt;
}
int main () {
    ll a , b , c , d , e , f ;
    cin >> a >> b >> c >> d >> e >> f ;

    int max_all = -1, max_sugar = -1,sugar;
  double max_con = -1;
  for (int i = 0; i <= f/(100*a); i++) {
    for (int j = 0; j <= f/(100*b); j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      int water = 100*a*i + 100*b*j;
      
      if (water > f) {
        break;
      }
      int sugar = max_sugar_sub(water/100, c, d, e, f);
      
      double con = (double)sugar / (double)(water+sugar);
      
      if (con > max_con) {
        max_con = con;
        max_all = water + sugar;
        max_sugar = sugar;
        
      }
      
    }
  }
  
  printf("%d %d\n",max_all, max_sugar);

    return 0 ;
}

 
