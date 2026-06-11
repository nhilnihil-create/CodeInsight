#include<bits/stdc++.h>
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
int gcd(int x, int y){
    return (x % y)? gcd(y, x % y): y; 
}
int main () {
    int N; cin >> N;
  
  ll a = 0, b = 0;
  rep(x,N) {
    ll S, T; cin >> S >> T;
    if(S*(b/T+(b%T!=0)) >= a)
      a = S*(b/T+(b%T!=0)), b = (b/T+(b%T!=0))*T;
    else
      a = (a/S+(a%S!=0))*S, b = T*(a/S);
    if(x == 0) a = S, b = T;
  }
  
  cout << a + b << "\n";
    return 0 ;
}

 
