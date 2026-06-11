#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}


int nextInt() { int x; scanf("%d", &x); return x;}

const int MAX_N = 112345;
ll X[MAX_N];
int W[MAX_N];

vector<int> solve(int N, ll L, ll T) {
  vector<int> res(N);
  if (count(W, W+N, 1) == N) {
    REP(i, N) res[i] = (X[i] + T) % L;
    return res;
  }
  if (count(W, W+N, 2) == N) {
    REP(i, N) res[i] = ((X[i] - T) % L + L) % L;
    return res;
  }

  vector<int> Y(N);
  REP(i, N) {
    if (W[i] == 1) Y[i] = (X[i] + T) % L;
    else Y[i] = ((X[i] - T) % L + L) % L;
  }
  sort(ALL(Y));
  // pv(ALL(Y));

  int o = 0;
  while (W[o] == 2) o++;
  // W[o] == 1

  ll co = 0;
  REP(i, N) if (i != o) {
    if (W[i] == 2) {
      ll t = T;
      if (o < i) {
        if (t >= (X[i]-X[o])/2) {
          co++;
          t -= (X[i]-X[o])/2;
          co += 2*t/L;
        }
      } else {
        if (t >= (L-X[o]+X[i])/2) {
          co++;
          t -= (L-X[o]+X[i])/2;
          co += 2*t/L;
        }
      }
    }
  }
  int y0 = (X[o] + T) % L;
  int p;
  for (p = N - 1; p >= 0; p--) if (y0 == Y[p]) break;
  // cout << "co=" << co << " " << y0 << " " << p <<  endl;
  REP(i, N) res[(co+o+i) % N] = Y[(p+i) % N];
  return res;
}

int main2() {
  int N = nextInt();
  ll L = nextInt();
  ll T = nextInt();
  REP(i, N) { X[i] = 2*nextInt(); W[i] = nextInt(); }
  vector<int> ans = solve(N, 2*L, 2*T);  
  REP(i, ans.size()) printf("%d\n", ans[i]/2);
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
