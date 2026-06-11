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

  for(int i = 0; i <= 30;i++)
  for(int j = 0; j <= 30;j++)
  {
    ll sum = (i * a + j * b) * 100;
    if(sum <= f)
      x.push_back(sum);
  }

  for(int i = 0; i <= 3000;i++)
  for(int j = 0; j <= 3000;j++)
  {
    ll sum = (i * c + j * d);
    if(sum <= f)
      y.push_back(sum);
  }

  double noudo = 0;
  ll ans_x = 100 * a,ans_y = 0;

  rep(i,sz(x))
  rep(j,sz(y))
  {
    ll sum = x[i] + y[j];
    ll sug = y[j];

    if(0 < sum && sum <= f)
    {
      if(sug > (x[i] / 100) * e)continue;
      double buf = (double)sug / sum;
      if(noudo < buf)
      {
        noudo = buf;
        ans_x = sum;
        ans_y = sug;
      }
    }

  //   if(y[j] * 100 > e * x[i])continue;
  //   if(!(0 < x[i] + y[j] && x[i] + y[j] <= f))continue;
  //   double buf = (double)y[j] / (x[i] + y[j]) * 100;
  //   if(noudo < buf)
  //   {
  //     noudo = buf;
  //     ans_x = x[i];
  //     ans_y = y[j];
  //   }
  }

  cout << ans_x << " " << ans_y << endl;
  

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
