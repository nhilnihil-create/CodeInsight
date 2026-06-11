#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  int start = max(A,C);
  int end = min(B,D);
  int ans = end - start;
  ans = max(0,ans);
  
  cout << ans << endl;
}