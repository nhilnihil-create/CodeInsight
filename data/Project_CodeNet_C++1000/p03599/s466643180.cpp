#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


int main() {
  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<int> water(31,0),sugar(1501,0);
  rep(i,30/a+1) {
    rep(j,30/b+1) {
      if (a*i+b*j<=30) water[a*i+b*j]=1;
      else break;
    }
  }

  rep(i,1500/c+1) {
      rep(j,1500/d+1) {
        if (c*i+d*j<=1500) sugar[c*i+d*j] = 1;
        else break;
      }
  }


  int answ=100*a,anss=0;
  rep2(i,1,31) {
    if (water[i]==0) continue;
    auto t = i*e;//tまで溶ける
    for (int j=t;j>0;j--) {
      double ansp = (double) anss/(double) (anss+answ), np = (double) j/(double) (j+i*100);
      // cout << ansp << ' ' << np << endl;
      if (sugar[j] && 100*i+j<=f && ansp < np ) {
        anss = j;
        answ = 100*i;
        break;
      } 
    }
  }
  cout << answ+anss << ' ' << anss << endl;
 }