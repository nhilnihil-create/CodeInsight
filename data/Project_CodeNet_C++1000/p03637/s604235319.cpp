/**
 *  winners never quit
**/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pp pop_back
#define mp make_pair
typedef long long Long;
void FastIO(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
}

const int N = 1e6;

int main()
{
  FastIO();
  int tc, ca = 0;
  int n;
  cin >> n;
  vector <int> v(4, 0);
  int el;
  for (int i = 0;i < n;i++){
    cin >> el;
    v[el%4]++;
  }
  int f = v[0] + (v[2]/2);
  if (f >= n/2)cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}
