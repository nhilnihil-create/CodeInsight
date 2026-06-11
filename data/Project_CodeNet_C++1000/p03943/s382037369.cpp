#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
 
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pi;


int main() {
  vi a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());
  
  if (a[0] + a[1] == a[2]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}