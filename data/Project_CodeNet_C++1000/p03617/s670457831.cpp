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
int getDigit(long long n);      // 数字の桁数を取得する。
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
typedef struct val{
  ll value;
  ll val_p_lit; // 2lあたりの値段
  double lit;
} VAL;

int main() {

  ll q,h,s,d,n;
  vector<VAL> a(4);

  cin >> q >> h >> s >> d >> n;

  a[0].lit = 0.25;
  a[1].lit = 0.5;
  a[2].lit = 1.0;
  a[3].lit = 2.0;
    
  a[0].value = q;
  a[1].value = h;
  a[2].value = s;
  a[3].value = d;

  a[0].val_p_lit = a[0].value * 8;
  a[1].val_p_lit = a[1].value * 4;
  a[2].val_p_lit = a[2].value * 2;
  a[3].val_p_lit = a[3].value;

  auto comp = [](auto a,auto b)
  {
    return a.val_p_lit < b.val_p_lit;
  };

  sort(all(a),comp);

  ll ans = 0;
  rep(i,4)
  {
 
    ll buf = n / a[i].lit;
    n = n - buf * a[i].lit;
    ans += buf * a[i].value;
	if(n == 0) break;
  }

  cout << ans << endl;

  return 0;
}
// funcの実体
// ------------------------------------------------
int getDigit(ll n)
{
  int i = 1;
  while(1)
  {
    n = n / 10;
    if(n == 0)
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
