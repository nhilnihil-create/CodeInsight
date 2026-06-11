#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(), v.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;

void partial_calc(string &S,vector<ll>&ans,ll i)
{
    if(i>(S.size()-1))
      return;

  ll temp1=1,temp2=1,temp3=1,sum=0;
  rep(j,i)
  {
    temp2 = temp2 * 2;
  }

  rep(j, (S.size()-i))
  {
    temp3 = 1;
    if((i+j+2)<S.size())
    rep(k, S.size() - (i + j+2))
    {
      temp3 = temp3 * 2;
    }
    sum = sum + (S[i]-'0') * temp1 * temp2*temp3;
    temp1 = temp1 * 10;
  }

  ans[i] = sum;

  partial_calc(S, ans, i + 1);
}

ll sum_calc(string &S)
{
  ll sum=0;
  vector<ll> ans(S.size());
  partial_calc(S, ans, 0);
  rep(i,S.size())
  {
    sum += ans[i];
  }
  return sum;
}

int main()
{
  string S;
  cin >> S;
  cout << sum_calc(S) << endl;
}
