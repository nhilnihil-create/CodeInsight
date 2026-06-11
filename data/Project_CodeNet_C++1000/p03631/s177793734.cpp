#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ll long long
long long min(long long x,long long y){return (x<y ? x:y);}
long long max(long long x,long long y){return (x>y ? x:y);}
#define ld long double
int stoi(string s) {return atoi(s.c_str());}
int keta(long long x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
ll gcd(ll x, ll y){ll a,b; if(x>y){a=x; b=y;} else{a=y;b=x;} return (a%b==0 ? b: gcd(b,a%b));}
ll lcm(ll x, ll y){return x/gcd(x,y) * y;}

int main(){
  int N; cin >> N;
  cout << ( (N%10 == N/100) ? "Yes\n": "No\n");
}