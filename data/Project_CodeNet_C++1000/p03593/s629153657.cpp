#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  int h, w;
  vector<int> cnt(30);
  cin >> h >> w;
  rep(i, h) rep(j, w) 
  {
    char c;
    cin >> c;
    cnt[c - 'a']++;
  }
  priority_queue<int> que;
  rep(i, 30)
  {
    if(cnt[i]) que.push(cnt[i]);
  }
  
  int hh = h - (h & 1), ww = w - (w & 1);
  int n1 = h & w & 1;
  int n2 = (((h & 1) * ww) + ((w & 1) * hh)) / 2;
  int n4 = (h * w - 2 * n2 - n1) / 4;
  
  
  
  rep(i, n4)
  {
    int a;
    a = que.top();
    que.pop();
    a -= 4;
    if(a < 0)
    {
      cout << "No" << endl;
      return 0;
    }
    if(a != 0) que.push(a);
  }
  
  rep(i, n2)
  {
    int a;
    a = que.top();
    que.pop();
    a -= 2;
    if(a < 0)
    {
      cout << "No" << endl;
      return 0;
    }
    if(a != 0) que.push(a);
  }
  
  cout << "Yes" << endl;
  
  return 0;
}