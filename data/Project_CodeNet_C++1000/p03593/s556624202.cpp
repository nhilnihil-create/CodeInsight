#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int h,w;
  cin >> h >> w;
  vector<int> count(26,0);
  int i;
  rep(i,h*w)
  {
    char c;
    cin >> c;
    count[c-'a']++;
  }
  bool ok = true;
  if(h%2 == 0 && w%2 == 0)
  {
    rep(i,26)
    {
      if(count[i]%4 != 0) ok = false;
    }
  }
  else if(h%2 == 0 || w%2 == 0)
  {
    if(w%2 == 0) swap(h,w);
    int k = h/2;
    int m = w/2;
    priority_queue<int> pq;
    rep(i,26)
    {
      pq.push(count[i]);
    }
    rep(i,k*m)
    {
      int now = pq.top();
      pq.pop();
      pq.push(now-4);
    }
    rep(i,k)
    {
      int now = pq.top();
      pq.pop();
      pq.push(now-2);
    }
    while(!pq.empty())
    {
      int now = pq.top();
      pq.pop();
      if(now != 0) ok = false;
    }
  }
  else
  {
    int k = h/2;
    int m = w/2;
    priority_queue<int> pq;
    rep(i,26)
    {
      pq.push(count[i]);
    }
    rep(i,k*m)
    {
      int now = pq.top();
      pq.pop();
      pq.push(now-4);
    }
    rep(i,k+m)
    {
      int now = pq.top();
      pq.pop();
      pq.push(now-2);
    }
    int now = pq.top();
    pq.pop();
    pq.push(now-1);
    while(!pq.empty())
    {
      int now = pq.top();
      pq.pop();
      if(now != 0) ok = false;
    }
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}