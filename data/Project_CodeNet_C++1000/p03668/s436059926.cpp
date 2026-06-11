#define _GLIBCXX_DEBUG //test only

#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define INF 1020304050

int main()
{
  int n;
  cin >> n;
  vector<int> x(n-1);
  vector<int> y(n-1);
  int i;
  rep(i,n-1)
  {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<vector<int>> e(n);
  rep(i,n-1)
  {
    e[x[i]].emplace_back(y[i]);
    e[y[i]].emplace_back(x[i]);
  }
  vector<int> root(n,-1);
  stack<int> st;
  queue<int> q;
  queue<int> q2;
  vector<int> grundy(n,0);
  q.push(0);
  while(!q.empty())
  {
    while(!q.empty())
    {
      int now = q.front();
      q.pop();
      rep(i,e[now].size())
      {
        int to = e[now][i];
        if(to != 0 && root[to] == -1)
        {
          root[to] = now;
          q2.push(to);
          st.push(to);
        }
      }
    }
    while(!q2.empty())
    {
      q.push(q2.front());
      q2.pop();
    }
  }
  while(!st.empty())
  {
    int now = st.top();
    st.pop();
    if(e[now].size()==1)
    {
      grundy[now] = 1;
    }
    else
    {
      int kg = 0;
      rep(i,e[now].size())
      {
        int from = e[now][i];
        if(from == root[now]) continue;
        kg = kg^grundy[from];
      }
      grundy[now] = kg+1;
    }
  }
  int judge = 0;
  rep(i,e[0].size())
  {
    judge = judge^grundy[e[0][i]];
  }
  if(judge == 0)
  {
    cout << "Bob" << endl;
  }
  else
  {
    cout << "Alice" << endl;
  }
  
}
