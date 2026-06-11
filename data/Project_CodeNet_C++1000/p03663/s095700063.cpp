#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>bool chmin(T&a,const T&b){return a>b?(a=b,1):0;}
template<class T>bool chmax(T&a,const T&b){return a<b?(a=b,1):0;}


int nextInt() { int x; scanf("%d", &x); return x;}

int N;
bool query(ll n) {
  // return (n <= N) == (to_string(n) <= to_string(N));
  cout << "? " << n << endl;
  string res;
  cin >> res;
  return res[0] == 'Y';
}

bool answer(ll n) {
  cout << "! " << n << endl;
  // if (n != N) {cout << "wrong answer : N=" << N << " n=" << n << endl;}
  // return n == N;
  return true;
}

int main2() {

  ll lo = 10000000000LL;
  ll hi = 100000000000LL;
  while (hi - lo > 1) {
    ll mid = (hi + lo) / 2;
    if (query(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  ll n = hi;
  for (;;) {
    if (query(n - 1)) {
      break;
    }
    n /= 10;
  }
  if (n == 10000000001) {
    n = 9;
    for (;;) {
      if (query(n)) break;
      n = n * 10 + 9;
    }
    n = (n + 1) / 10;
  }
  answer(n);
  return 0;
}

int main() {
  // for (int i = 1; i <= 20000; i++) {
    // N = i;
    // main2();
  // }
  main2();
  return 0;
}

