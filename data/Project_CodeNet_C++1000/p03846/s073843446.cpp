#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>
#include <iomanip>
#include <math.h>
#include <assert.h>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr long long int infll = 1001001001001001LL;
constexpr int INF = 1000000007;
constexpr int inf = 1000000007;
const int mod = 1000000007;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}


template <typename T>
T seinomi(T a)
{
    if (a > 0)
    {
        return a;
    }
    else
    {
        return 0;
    }
}

template <typename T>
map<T, T> soinsuubunkai(T n) //連想配列[素因数f.first][個数f.second]
{
    map<T, T> ret;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1)
        ret[n] = 1;
    return ret;
}

template <typename T>
T ketasuu(T num)
{
    return std::to_string(num).length();
}

int kaizyou(int k)
{
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

ll modkaizyou(ll k)
{
    ll sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
        sum=sum%mod;
    }
    return sum;
}

template <class ForwardIt, class T>
void iota(ForwardIt first, ForwardIt last, T value)
{
    while (first != last)
    {
        *first++ = value;
        ++value;
    }
}

//整数乗
int llpow(ll a, ll n){//aのn乗を計算します。
  ll x = 1;
  while(n > 0){//全てのbitが捨てられるまで。
    if(n&1){//1番右のbitが1のとき。
      x = x*a;
    }
    a = a*a;
    n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
  }
  return x;
}


long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


template <typename T>
T amarinasi(T a,T b){
    if(a%b==0)
{
    return a/b;
}
else if(a%b>0)
{
    return a/b+1;
}
else
{
    return a/b-1;
}
}

//組み合わせ nCr
void nCr_Calculater(vector<vector <long long int> > &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}
ll nCr(ll N,ll K){
  vector<vector<long long int> > v(N+1,vector<long long int>(N+1,0));
  nCr_Calculater(v);
  return v[N][K];
}

//順列　nPr
ll nPr(ll n,ll r){
    r = n - r;
    ll sum = 1;
    ll i;
    for (i=n;i>=r+1;i--)sum*=i;
    return sum;
}

//重複組み合わせ　nHr = (r+n-1)Cr
ll nHr(ll n,ll r){
    return nCr(r+n-1,r);
}

//小数点以下10桁テンプレート（main関数内の最初に貼付け）
//std::cout << std::fixed << std::setprecision(10);

//----------------------------------------------------------------


int main() {
    ll n;
    cin>>n;
    map<ll,ll>rensou;
    ll a;
    for(ll i=0;i<n;i++){
        cin>>a;
        rensou[a]++;
    }
    if(n%2==0){
        bool flag=true;
        for(auto f:rensou){
            if(f.first%2==0){
                if(f.second!=2){
                    flag=false;
                }
            }
        }
        if(flag){
            cout<<modpow(2,n/2,mod)<<endl;
        }else{
            cout<<0<<endl;
        }
    }else{
        bool flag=true;
        for(auto f:rensou){
            if(f.first==0){
                if(f.second!=1){
                    flag=false;
                }
            }
            else if(f.first%2){
                if(f.second!=2){
                    flag=false;
                }
            }
        }
        if(flag){
            cout<<modpow(2,n/2,mod)<<endl;
        }else{
            cout<<0<<endl;
        }
    }
}

