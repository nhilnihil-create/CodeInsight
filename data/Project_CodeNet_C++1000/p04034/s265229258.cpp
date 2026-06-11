#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n,m;cin>>n>>m;
  vector<int> x(m);
  vector<int> y(m);
  int i;
  rep(i,m)cin>>x[i]>>y[i];
  rep(i,m)
  {
    x[i]--;
    y[i]--;
  }
  vector<int> balls(n,1);
  vector<bool> prob(n,false);
  prob[0]=true;
  rep(i,m)
  {
    balls[x[i]]--;
    balls[y[i]]++;
    if(prob[x[i]])
    {
      prob[y[i]]=true;
    }
    if(balls[x[i]]==0)
    {
      prob[x[i]]=false;
    }
  }
  int ans=0;
  rep(i,n)if(prob[i])ans++;
  cout<<ans<<endl;
}
