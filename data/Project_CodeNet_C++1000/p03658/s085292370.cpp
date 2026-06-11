#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> l(N);

  rep(i, N){
   cin >> l[i];
  }
  sort(l.begin(), l.end());
  reverse(l.begin(), l.end()); 
  int ans = 0;
  rep(i, K){
    ans += l[i];
  }
  print(ans);
}
