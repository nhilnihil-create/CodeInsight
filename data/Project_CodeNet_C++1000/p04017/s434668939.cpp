#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using P = pair<int, int>;
using MATRIX = vector< vector<ll> >;

int N, L, Q;
int x[100000];
vector<P> query;
int nxt[20][100000];
int NUM;
const int INF = 1000000000;

int calc(int a, int key) {
  int temp = a;
  for(int i = NUM; i >= 0; i--) {
    if((key>>i) & 1) {
      temp = nxt[i][temp];
      if(temp == INF) return temp;
    }
  }
  return temp;
}

int isOk(int a, int b, int key) {
  if(calc(a, key) >= b) return true;
  return false;
}

int lower_search(int a, int b) {
  int l = -1, r = N;
  while(r - l > 1) {
    int half = (r + l) / 2;
    if(isOk(a, b, half)) r = half;
    else l = half;
  }
  return r;
}

int main() {
  cin >> N;
  NUM = floor(log2(N));
  rep(i, NUM+1) {
    rep(j, N) {
      nxt[i][j] = INF;
    }
  }
  rep(i, N) {
    cin >> x[i];
  }
  cin >> L;
  cin >> Q;

  rep(i, Q) {
    int a, b;
    cin >> a >> b;
    a--;b--;
    query.push_back({a, b});
  }

//尺取り法で１日で移動できる場所を求める。
  int srt = 0;
  int end = 1;
  while(true) {
    if(srt == N-1) break;
    if(x[end]-x[srt] > L) {
      nxt[0][srt] = end-1;
      srt++;
    } else {
      if(end != N-1) {
        end++;
      } else if(end == N-1) {
        nxt[0][srt] = end;
        srt++;
      } 
    }
  }

  // rep(i, N) {
  //   if(i == N-1) continue;
  //   int temp = 0;
  //   for(int j = i+1; j < N; j++) {
  //     int cand = temp;
  //     temp += x[j] - x[j-1];
  //     if(temp > L) {
  //       nxt[0][i] = j-1;
  //       break;
  //     } 
  //   }
  //   if(temp <= L) nxt[0][i] = N-1;
  // }

  rep(i, NUM) {
    rep(j, N) {
      if(nxt[i][j] == INF) nxt[i+1][j] = INF;
      else {
        nxt[i+1][j] = nxt[i][nxt[i][j]];
      }
    }
  }

  rep(i, Q) {
    int u = query[i].first;
    int v = query[i].second;
    if(u > v) swap(u, v);
    cout << lower_search(u, v) << endl;
  }

  // rep(i, NUM+1) {
  //   rep(j, N) {
  //     cout << nxt[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  return 0;
}