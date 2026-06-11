#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
vector<long long> enum_divisors(long long N)
{
  vector<long long> res;
  for (long long i = 1; i * i <= N; ++i)
  {
    if (N % i == 0)
    {
      res.push_back(i);
      // 重複しないならば i の相方である N/i も push
      if (N / i != i) res.push_back(N / i);
    }
  }
  // 小さい順に並び替える
  sort(res.begin(), res.end());
  return res;
}

int main()
{
  ll N;
  cin >> N;
  vector<ll> vec = enum_divisors(N);
  int M = vec.size();
  if(M%2==1)
  {
    int digits = 0;
    ll n = vec[M/2];
    while(n>0)
    {
      n /= 10;
      digits ++;
    }
    cout << digits << endl;
  }
  else
  {
    int digits1 = 0;
    int digits2 = 0;
    ll n1 = vec[M/2-1];
    ll n2 = vec[M/2];
    while(n1>0)
    {
      n1 /= 10;
      digits1 ++;
    }
    while(n2>0)
    {
      n2 /= 10;
      digits2 ++;
    }
    cout << max(digits1,digits2) << endl;
  }
  return 0;
}
