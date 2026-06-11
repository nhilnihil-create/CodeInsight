#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

const long long INF = 1LL << 60;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<pair<ll, ll> > a(N);
  vector<pair<ll, ll> > c(M);
  
  rep(i, N){
    cin >> a[i].first >> a[i].second;
  }

  rep(i, M){
    cin >> c[i].first >> c[i].second;
  }

  ll m = 0, m_len = INF, len;
  rep(i, N){
    m = 0;
    m_len = INF;
    rep(j, M){
      len = abs(a[i].first - c[j].first) + abs(a[i].second - c[j].second);
      if (len < m_len){
        m_len = len;
        m = j + 1;
      }
    }
    print(m);
  }

}
