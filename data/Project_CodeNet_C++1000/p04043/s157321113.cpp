#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int A, B, C, D = 0, E = 0;
  cin >> A >> B >> C;
  if (A == 5) D++;
  if (B == 5) D++;
  if (C == 5) D++;
  if (A == 7 || B == 7 || C ==7)
    E++;
  if (D == 2 && E == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}