#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
  string a,b,c;
  cin >> a >> b >> c;
  if(a[a.size()-1] == b[0] && b[b.size()-1] == c[0]){
    cout << "YES" << "\n";
  }else{
    cout << "NO"<< "\n";
  }
}