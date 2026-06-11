// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repr(i,n) for (int i = 0; i < (f); --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100;
const int INF = (1<<12);

int func(ll a, ll b, ll c){
  if((a%2==1) || (b%2)==1 || (c%2) == 1) return 0;
  if((a == b && b == c)) return -1;
  return func((b+c)/2, (c+a)/2, (a+b)/2) + 1;
}

int main() {
  ll a,b,c;
  cin >> a >> b >> c;
  cout << func(a,b,c) << endl;
  return 0;
}