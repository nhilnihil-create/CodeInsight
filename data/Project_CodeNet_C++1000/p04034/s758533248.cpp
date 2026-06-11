#include <bits/stdc++.h>
using namespace std;


int num[100005] = {0};
int red[100005] = {0,1};


void debug(int n)
{
  for (int i = 1; i <= n; i++) {
    cout << num[i];
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    if (red[i])
    {
      cout << 'r';
    }
    else
    {
      cout << ' ';
    }
  }
  cout << endl;
}


int main()
{
  fill(num,num+100005,1);
  int n; cin >> n;
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    int x,y; cin >> x >> y;
    num[x] -= 1;
    num[y] += 1;
    if (red[x])
    {
      red[y] = 1;
    }
    if (num [x] == 0)
    {
      red[x] = 0;
    }
    //debug(n);
  }
  int sum = 0;
  for (int i = 1; i < 100001; i++) {
    if (red[i])
    {
      sum ++;
    }
  }
  cout << sum << endl;
}