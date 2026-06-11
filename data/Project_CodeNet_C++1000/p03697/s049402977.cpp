#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 100100100;
using namespace std;

int main()
{
  int a,b;
  int res=0;
  cin >> a>>b;

  res = (a+b<10);
  if(res) cout << a+b << endl;
  else cout << "error" << endl;
}