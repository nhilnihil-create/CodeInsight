#include <stdio.h>
#include <iostream>
#include <math.h>
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
  int N, f = 0, t = 0, o = 0;
  cin >> N;
  vector<ll> a(N);

  rep(i, N){
    cin >> a[i];
    if(a[i]%4==0) f++;
    else if(a[i]%2 == 0) t++;
    else o++;
  }

  
  if(t>0) t=1;

  if(f >= o + t - 1){
    print("Yes");
  } else {
    print("No");
  }

}
