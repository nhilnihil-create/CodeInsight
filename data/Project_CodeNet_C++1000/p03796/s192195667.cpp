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

const long long INF = 1LL << 60;
const ll MOD = pow(10, 9) + 7;

int main() {
  ll ans=1, N;
  cin >> N;

  rep(i, N){
    ans = ans * (i+1)%MOD;
  }
  print(ans%MOD);

}
