#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
  int x,y;
  cin >> x >> y;
  vector<int> a = {1, 3, 5, 7, 8, 10, 12, 4, 6, 9, 11, 2};
  auto it = find(a.begin(),a.end(),x);
  auto it2 = find(a.begin(),a.end(),y);
  int nx = it -a.begin();
  int ny = it2-a.begin();
  if(max(nx,ny) < 7 || (7 <= min(nx,ny) && max(nx,ny) <= 10 )|| 10 < min(nx,ny)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}