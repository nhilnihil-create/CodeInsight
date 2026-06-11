// include
// ------------------------------------------------
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// func
// ------------------------------------------------
int CalcSumOfDigit(int n);      // 各桁の和を計算する。
string upper(string str);       // 英字を大文字に変換する。
string lower(string str);       // 英字を小文字に変換する。

// define
// ------------------------------------------------
#define all(a)        (a).begin(),(a).end()
#define rall(a)       (a).rbegin(),(a).rend()
#define pb            push_back
#define sz(a)         int((a).size())
#define rep(i,n)      for(int(i)=0;(i)<(n);(i)++)
#define repe(i,n)     for(int(i)=0;(i)<=(n);(i)++)
#define vsort(v)      sort((v).begin(),(v).end())
#define rvsort(v)     sort(rall((v)))
#define vi            vector<int>
#define GCD(a,b)      __gcd((a),(b))
#define LCM(a,b)      (a)/GCD((a),(b))*(b)

const int INF = 1e9;

using ull = unsigned long long;
using ll = long long;

// code
// ------------------------------------------------
int main() {

  ll n;
  cin >> n;
  vector<ll>  a(n);
  rep(i,n) cin >> a[i];

  ll m = 0; // 累積和
  ll p = 0; // 同じく
  ll m_cnt = 0; // 各スタートでの操作回数
  ll p_cnt = 0;

  rep(i,n)
  {
    // minus start
    if( (i % 2 ? 1 : -1 ) * (m + a[i]) < 0)
    {
      // 符号が違っていたら
      ll b_m = m + a[i];
      m_cnt += 1 + abs(b_m);
      m = i % 2 ? 1 : -1;
    }
    else if(m + a[i] == 0)
    {
      m = i % 2 ? 1 : -1;
      m_cnt++;
    }
    else
    {
      // あっているなら次に行くだけ
      m += a[i];
    }
    
    // plus start
    if( (i % 2 ? -1 : 1 ) * (p + a[i]) < 0)
    {
      // 符号が違っていたら
      ll b_p = p + a[i];
      p_cnt += 1 + abs(b_p);
      p = i % 2 ? -1 : 1;
    }
    else if(p + a[i] == 0)
    {
      p = i % 2 ? -1 : 1;
      p_cnt++;
    }
    else
    {
      // あっているなら次に行くだけ
      p += a[i];
    }
  }

  cout << min(m_cnt,p_cnt) << endl;


  return 0;
}

// funcの実体
// ------------------------------------------------
int CalcSumOfDigit(int n)
{
  int s = 0;
  while(n)
  {
    s += n % 10;
    n = n / 10;
  }
  return s;
}

string upper(string str)
{
  for(auto itr = str.begin();itr != str.end() ; itr++)
  {
    if(97 <= *itr && *itr <= 122)
    {
      *itr = *itr - 32;
    }
  }
  return str;
}

string lower(string str)
{
  for(auto itr = str.begin();itr != str.end() ; itr++)
  {
    if(65 <= *itr && *itr <= 90)
    {
      *itr = *itr + 32;
    }
  }
  return str;
}