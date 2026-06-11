#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vector<int>city(n);
  rep(i,n)cin>>city[i];
  int l,q;
  cin>>l>>q;
  int nl=n,c=0;
  while(nl>0){c++;nl/=2;}
  vector<vector<int>>db(n,vector<int>(c,n));
  int r=0;
  rep(i,n)
  {
    while(r+1<n&&city[r+1]<=city[i]+l)r++;
    db[i][0]=r;
  }
  rep(i,c-1)
  {
    rep(j,n)
    {
      db[j][i+1]=db[db[j][i]][i];
    }
  }
  rep(i,q)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    if(a>b)swap(a,b);
    int cnt=0;
    for(int j=c-1;j>=0;j--)
    {
      if(db[a][j]<b)
      {
        a=db[a][j];
        cnt+=1<<j;
      }
    }
    cout<<cnt+1<<"\n";

  }
  cout<<flush;


  return 0;

}
