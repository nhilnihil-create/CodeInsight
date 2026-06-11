#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

ll gcd (ll a, ll b){
  if (b == 0)
    return a;
  return gcd (b, a%b);
}

ll arr[100005];
int main() {
  ll n, k;
  cin >> n >> k;

  ll dcg;
  ll max = -10000000;
  for (ll i = 1; i <= n; i++){
    cin >> arr[i];
    if (arr[i] > max){
      max = arr[i];
    }
    if (i == 1){
      dcg = arr[1];
    }
    else if (i > 1){
      dcg = gcd(arr[i],dcg);
    }
  }

  if (max < k){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  if (dcg != 1){
    if (gcd (k,dcg) != dcg){
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  cout << "POSSIBLE" << endl;
  return 0;
}