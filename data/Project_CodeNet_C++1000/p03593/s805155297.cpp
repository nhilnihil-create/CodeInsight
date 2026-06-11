#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <functional>
#include <set>
#define DB cerr<<"D"<<endl
#define pb push_back
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";} template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";} template<typename T> void caut(T a){cout<<"("<<a<<") ";}
using P=pair<double,int>;
const ll M = 1e9+7;
void add(ll& x, ll y) {x+=y; x%=M;}
void chmax(ll& x, ll y) {if (x<y) x=y;}
ll mod_pow(ll x, ll a) { ll an = 1; while(a > 0) { if (a&1) an = an * x % M; x = x * x % M; a >>= 1;} return an;}

int main() {
  int h,w; cin>>h>>w;
  int u[26]={};
  for(int i=0;i<h;i++) {
    string s; cin>>s;
    for(int j=0;j<w;j++) {
      u[s[j]-'a']++;
    }
  }
  int m4=0, m2=0, m1=0;
  if (h%2==1 && w%2==1) {
    m1 = 1;
    m2 = h+w-2*m1;
    m4 = h*w-(m1+m2);
  } else if (h%2==1) {
    m1 = 0;
    m2 = w;
    m4 = h*w-m2;
  } else if (w%2==1) {
    m1 = 0;
    m2 = h;
    m4 = h*w-m2;
  } else {
    m1 = m2 = 0; m4 = h*w;
  }
  m2/=2; // 上と左だけでよい
  m4/=4; // 左上部分だけでよい

  for(int i=0,j=0;i<m4;i++) {
    if (j == 26) {
      cout<<"No"<<endl;
      return 0;
    }
    if (u[j] >= 4) {
      u[j]-=4;
    } else {
      j++; i--;
    }
  }

  for(int i=0,j=0;i<m2;i++) {
    if (j == 26) {
      cout<<"No"<<endl;
      return 0;
    }
    if (u[j] >= 2) {
      u[j]-=2;
    } else {
      j++; i--;
    }
  }

  for(int i=0,j=0;i<m1;i++) {
    if (j == 26) {
      cout<<"No"<<endl;
      return 0;
    }
    if (u[j] >= 1) {
      u[j]-=1;
    } else {
      j++; i--;
    }
  }
  cout<<"Yes"<<endl;
}