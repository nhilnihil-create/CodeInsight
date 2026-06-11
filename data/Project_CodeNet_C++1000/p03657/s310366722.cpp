#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 100100100;
using namespace std;

int main()
{
  int A,B;
  bool res=false;
  cin >> A>>B;

  if(A%3==0) res=true;
  if(B%3==0) res=true;
  if((A+B)%3==0) res=true;

  if(res) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}
