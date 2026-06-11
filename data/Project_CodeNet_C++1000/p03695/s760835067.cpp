#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
# include <bits/stdc++.h>
using namespace std;
long long powerexp(long long base, long long exp, int mod) {
   long long res = 1;
   while (exp > 0) {
      if (exp % 2 == 1)
         res= (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}
int gcd(int a, int b)
{
    int c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
void PrintVector(vector<long long int> v,long long int n)
{
 
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void Takevector(vector<long long int> &v,long long int n)
{
  for(long long int i=0;i <n;i++)
  { long long int number;
    cin>>number;
    v.push_back(number);
  }
}
typedef long long int ll;
typedef vector<long long int> vi;
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define scl(x)         ll x;       scanf("%lld", &x);
#define scll(x, y)     ll x, y;    scanf("%lld %lld", &x, &y);
#define sclll(x, y, z) ll x, y, z; scanf("%lld %lld %lld", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
#define nl cout<<"\n";
int min(int x, int y)  
{  
    return (x < y)? x: y;  
      
}  
int main()
{
  
  
  int flag=1;
  ll sum=0;
  int flag1=0;
  ll tot=0;
  int ans=0;
  map<int,int>m;
  vi v;
  set<int>st;
  string s;
  int grey=0;
  int green=0;
  int yellow=0;
  int cyan=0;
  int red=0;
  int orange=0;
  int brown=0;
  int blue=0;
  int any=0;
  int n;
  cin>>n;
  while(n--){
  sci(m);
  if(m<400) grey++;
  else if(m<800) brown++;
  else if(m<1200) green++;
  else if(m<1600) cyan++;
  else if(m<2000) blue++;
  else if(m<2400) yellow++;
  else if(m<2800) orange++;
  else if(m<3200) red++;
  else if(m>=3200)any++;
}
int cnt=8;
  if(grey==0) cnt--;
  if(brown==0) cnt--;
  if(green==0) cnt--;
  if(cyan==0) cnt--;
  if(blue==0) cnt--;
  if(yellow==0) cnt--;
  if(orange==0) cnt--;
  if(red==0) cnt--;
  if(cnt>0){
  cout<<cnt<<" "<<any+cnt;}
  else{
    cout<<1<<" "<<any+cnt;
  }
  
    return 0;
}