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
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  int N, K, X, Y;
  cin >> N >> K >> X >> Y;
  int sum;
  if(N <= K) sum = N*X;
  else sum = K*X + (N-K)*Y;
  print(sum);

}
