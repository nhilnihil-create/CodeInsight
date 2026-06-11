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
int A[MAX_N];

int main2() {
  int N = nextInt();
  int M = nextInt();

  int odd = 0;
  REP(i, M) { 
    A[i] = nextInt();
    if (A[i] % 2 == 1) ++odd;
  }

  vector<int> ans;
  if (M == 1) {
    if (A[0] <= 2) { ans.push_back(A[0]); }
    else {
      ans.push_back(1);
      ans.push_back(A[0]-1);
    }
  } else if (odd <= 2) {
    for (int i = 0; i < M; i++) {
      if (A[i] % 2 == 1) {
        if (i > 0) swap(A[i], A[0]);
        break;
      }
    }
    for (int i = M - 1; i >= 0; i--) {
      if (A[i] % 2 == 1) {
        if (i != M-1) swap(A[i], A[M-1]);
        break;
      }
    }

    for (int i = 0; i < M; i++) {
      if (i == 0) ans.push_back(A[i]+1);
      else if (i == M-1) ans.push_back(A[i]-1);
      else ans.push_back(A[i]);
    }
  } else {
      // cout << "Impossible" << endl;
  }

  vector<int> tmp = ans;
  ans.clear();
  REP(i, tmp.size()) if (tmp[i] > 0) ans.push_back(tmp[i]);


  if (ans.size() == 0) {
    cout << "Impossible" << endl;
  } else {
    REP(i, M) {
      if (i > 0) cout << " ";
      cout << A[i];
    }
    cout << endl;

    cout << ans.size() << endl;
    REP(i, ans.size()) {
      if (i > 0) cout << " ";
      cout << ans[i];
    }
    cout << endl;

  }
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
