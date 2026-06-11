#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long
#define lli long long int

using namespace std;
using P = pair<int,int>;

int main(){

  int N, a;
  cin >> N;
  vector<int> vec(N);
  int ans = 0;

  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
  }
  sort(vec.begin(), vec.end());

  int sum = accumulate(vec.begin(), vec.end(), 0);
  int n = vec.size();

  if(sum%10 != 0){
    cout << sum << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if((sum -vec.at(i)) % 10 != 0){
      cout << sum -vec.at(i) << endl;
      return 0 ;
    }
  }

  cout << 0 << endl;

  return 0;
}