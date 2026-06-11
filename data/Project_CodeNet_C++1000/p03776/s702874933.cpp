#include<bits/stdc++.h>
#define rep(i, s, n) for (int i=(s); i<(n); i++)
#define ll long long
using namespace std;


ll com[52][52];
void nCr() {
  com[0][0]=1;
  rep(i, 1, 52) {
    rep(j, 0, i+1) {
      com[i][j]+=com[i-1][j];
      if (j>0) com[i][j]+=com[i-1][j-1];
    }
  }
}

int main() {
  int n, a,b;
  cin>>n>>a>>b;
  vector<ll> v(n);
  rep(i, 0, n) cin>>v[i];

  nCr();
  sort(v.begin(), v.end(), greater<ll>());
  ll sum=0;
  rep(i, 0, a) sum+=v[i];
  double res1=(double)(sum)/a;
  ll res2=0;
  int cnt=0;
  rep(i, 0, n) if (v[a-1]==v[i]) cnt++;
  if (v[0]==v[a-1]) rep(i, a, b+1) res2+=com[cnt][i];
  else {
    int tmp=0;
    rep(i, 0, a) if (v[a-1]==v[i]) tmp++; 
    res2=com[cnt][tmp];
  }
  cout<<setprecision(10)<<res1<<endl;
  cout<<res2<<endl;
}