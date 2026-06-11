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
  ll tot=0;
  string s;
  cin>>s;
  string str1,str2;
  int k=s.size()-2;
  while(k)
  {
    str1=s.substr(0,k/2);
    str2=s.substr(k/2,k/2);
   // cout<<str1<<" "<<str2<<endl;
    if(str1==str2)
    {
      cout<<k;
      break;
    }
    k-=2;
  }

  
    return 0;

  
  
}