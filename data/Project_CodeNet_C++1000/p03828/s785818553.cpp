//#include <bits/stdc++.h>
#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
 
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define SORT(a) sort(a.begin(), a.end()) //reverse()で反転
#define lower(a, n) lower_bound(a.begin(), a.end(), n);
#define upper(a, n) upper_bount(a.begin(), a.end(), n);
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int sum(int a){
  if(a == 0) return 0;
  return sum(a - 1) + a;
}
int gcd(int a, int b){ //最大公約数
  if(a % b == 0) return b;
  return gcd(b, a % b);
}
int lcm(int a, int b){ //最小公倍数
  return a / gcd(a, b) * b;
}
int main(){
  int n;
  cin >> n;
  map<int, int> a;
  for(int i = 2; i <= n; i++){
    int temp = i;
    for(int x = 2; x <= i; x++){
      while(true){
        if(temp % x == 0){
          temp /= x;
          a[x]++;
        }else break;
      }
    }
  }
  ll ans = 1;
  for(pii i : a){
    ans *= i.second + 1;
    ans %= mod;
  }
  cout << ans << endl;
}