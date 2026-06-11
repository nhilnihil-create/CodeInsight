#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <list>
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define crep(i) for(char i='a';i<='z';i++)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define psortfirst(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.first<b.first;});
#define ALL(x) (x).begin(),(x).end()
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
using namespace std;
using pii  = pair<int,int>;
long long gcd(long long a, long long b){return (b == 0 ? a : gcd(b, a%b));}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
typedef long long ll;
#define MOD 1000000007
#define EPS 10e-8

int main(){
  long h, w;
  cin >> h >> w;
  if((h%3)*(w%3)==0){
    cout << 0;
  }
  else {
    long ret = min(h, w);
    for(int i=0; i<h; i++){
      if(w%2==0){
        ret = min(ret, abs(i*w-(h-i)*w/2));
      }
      else {
        long dif = max({i*w, (h-i)*(w-1)/2, (h-i)*(w+1)/2})-min({i*w, (h-i)*(w-1)/2, (h-i)*(w+1)/2});
        ret = min(ret, dif);
      }
    }
    for(int i=0; i<w; i++){
      if(h%2==0){
        ret = min(ret, abs(i*h-(w-i)*h/2));
      }
      else {
        long dif = max({i*h, (w-i)*(h-1)/2, (w-i)*(h+1)/2})-min({i*h, (w-i)*(h-1)/2, (w-i)*(h+1)/2});
        ret = min(ret, dif);
      }
    }
    cout << ret;
  }
  return 0;
}
