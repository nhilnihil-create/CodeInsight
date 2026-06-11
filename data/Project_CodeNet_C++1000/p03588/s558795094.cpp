#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ll long long
long long min(long long x,long long y){return (x<y ? x:y);}
long long max(long long x,long long y){return (x>y ? x:y);}
#define ld long double
int stoi(string s) {return atoi(s.c_str());}
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
#define LINEY "YES\n"
#define Liney "Yes\n"
#define LINEN "NO\n"
#define Linen "No\n"


int main(){
  int N; cin >> N;
  ll worst_r =0;
  ll worst_v = pow(10,9)+1;
  ll a,b;
  REP(i,N){
    cin >> a >>b;
    if(a>worst_r){
      worst_r = a;
      worst_v = b;
    }
  }
  ll r = worst_r + worst_v;
  cout << r << "\n";
}