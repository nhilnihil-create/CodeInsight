#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#define ll long long

using namespace std;

int main(){

  ll n, a;
  cin >> n;
  int ans = 0;
  vector<ll> vec(n);

  for (int i = 0; i < n; i++){
    cin >> a;
    vec.at(i) = a;
  }

  ll now1 = 0, now2 = 0, cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    now1 += vec[i];
    now2 += vec[i];
    if(now1 <= 0){
      cnt1 += abs(now1)+1;
      now1 = 1;
    }
    if(now2 >= 0){
      cnt2 += abs(now2)+1;
      now2 = -1;
    }
    swap(now1, now2);
    swap(cnt1, cnt2);
  }

  cout << min(cnt1,cnt2) << endl;

  return 0;
}