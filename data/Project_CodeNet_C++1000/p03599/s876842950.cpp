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
int getDigit(int n);            // 数字の桁数を取得する。
string upper(string str);       // 英字を大文字に変換する。
string lower(string str);       // 英字を小文字に変換する。

// define
// ------------------------------------------------
#define all(a)        (a).begin(),(a).end()
#define rall(a)       (a).rbegin(),(a).rend()
#define sz(a)         int((a).size())
#define rep(i,n)      for(int(i)=0;(i)<(n);(i)++)
#define repe(i,n)     for(int(i)=0;(i)<=(n);(i)++)
#define vsort(v)      sort((v).begin(),(v).end())
#define rvsort(v)     sort(rall((v)))
#define vi            vector<int>
#define GCD(a,b)      __gcd((a),(b))
#define LCM(a,b)      (a)/GCD((a),(b))*(b)
#define kiriage(a,b)  ((a)+(b)-1)/(b)

const int INF = 1e9;

typedef long long ll;
typedef unsigned long long ull;

// code
// ------------------------------------------------
int main() {

  ll a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;

  vector<long long> x,y;

  double noudo = 0;
  ll ans_ws = 100 * a; // 水無しはだめなので…　満たせばいいので、100 * bでもいい
  ll ans_s = 0;

  for(int i = 0;i < 30;i++)
  for(int j = 0;j < 30;j++)
  {
    ll w = (i * a + j * b) * 100;
    for(int k = 0;k < f - w;k++)
    for(int l = 0;l < f - w - k;l++)
    {
      ll w = (i * a + j * b) * 100;
      ll s = k * c + l * d;
      ll sw = w + s;
      if(!(0 < sw && sw <= f))continue;
      if(w == 0) continue;  // 水なし
      if(s > w / 100 * e) continue; // 溶け残り
      double buf = (double)s / sw;
      if(noudo < buf)
      {
        noudo = buf;
        ans_ws = sw;
        ans_s = s;
      }
    }
  }
  cout << ans_ws << " " << ans_s << endl;
  

  return 0;
}
// funcの実体
// ------------------------------------------------
int getDigit(int n)
{
  int i = 1;
  while(1)
  {
    n = n / 10;
    if(n == 1)
      break;
    i++;
  }
  return i;
}
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
