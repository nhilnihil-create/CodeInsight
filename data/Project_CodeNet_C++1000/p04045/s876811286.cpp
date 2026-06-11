/**
 *  winners never quit
**/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long Long;
void FastIO(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}

const int N = 1e5;

int m[10];

int main()
{
  FastIO();
  int tc, ca = 0;
  int n, d, el;
  cin >> n >> d;
  for (int i = 0;i < d;i++){
    cin >> el;
    m[el]++;
  }
  bool ok = true;
  while (ok){
    int tm = n;
    bool check = false;
    while (tm){
      if (m[tm%10]){
        check = true;
        break;
      }
      tm /= 10;
    }
    ok = check;
    n++;
  }
  cout << n-1 << '\n';
  return 0;
}
