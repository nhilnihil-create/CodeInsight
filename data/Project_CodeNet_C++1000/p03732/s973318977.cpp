#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

#define int long long 

signed main()
{
  int n,w;
  cin>>n>>w;
  vector<vector<int>> a(4,vector<int>(0));
  int ww,tmp;
  cin>>ww>>tmp;
  a[0].emplace_back(tmp);
  for(int i=1; i<n; i++)
  {
    int s,t;
    cin>>s>>t;
    a[s-ww].emplace_back(t);
  }
  
  
  rep(i,4) sort(a[i].begin(), a[i].end(), greater<int>());
  rep(i,4) for(int j=0; j+1<a[i].size(); j++) a[i][j+1] += a[i][j];
 
  //rep(i,4){for(auto x:a[i]) cout<<x<<" "; cout<<endl;}
  int res = 0;
  for(int i=0; i<=a[0].size(); i++)
  {
    for(int j=0; j<=a[1].size(); j++)
    {
      for(int k=0; k<=a[2].size(); k++)
      {
        for(int l=0; l<=a[3].size(); l++)
        {
          if((i+j+k+l)*ww + j*1+k*2+l*3 > w) continue;
          int sum = 0;
          if(i) sum += a[0][i-1];
          if(j) sum += a[1][j-1];
          if(k) sum += a[2][k-1];
          if(l) sum += a[3][l-1];
          res = max(res, sum);
        }
      }
    }
  }
  cout<<res<<endl;
  
  //return 0;
}