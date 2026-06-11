#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;

  const int NUM_RATE = 9;//レート帯の数

  //レートからレート帯の番号を返す関数
  auto rate_to_idx = [&](int r){
    vector<P> edges;
    edges.push_back(make_pair(1,399));
    edges.push_back(make_pair(400,799));
    edges.push_back(make_pair(800,1199));
    edges.push_back(make_pair(1200,1599));
    edges.push_back(make_pair(1600,1999));
    edges.push_back(make_pair(2000,2399));
    edges.push_back(make_pair(2400,2799));
    edges.push_back(make_pair(2800,3199));
    edges.push_back(make_pair(3200,4800));

    rep(i,NUM_RATE){
      int lower = edges[i].first;
      int upper = edges[i].second;
      if(lower<=r&&r<=upper) return i;
    }

  };

  vector<int> p(NUM_RATE,0);//各レート帯の人数

  rep(i,n){
    int a;
    cin >> a;
    p[rate_to_idx(a)]++;
  }

  int zeros = 0;//人がいない色固定レート帯の数
  int exist_cols = 0;//人がいる色固定レート帯の数
  int strong = p[NUM_RATE-1];//色フリー帯にいる人数

  rep(i,NUM_RATE-1){
    if(p[i]==0) zeros++;
    else exist_cols++;
  }

  int ans_min = max(exist_cols,1);
  int ans_max = exist_cols + strong;
  printf("%d %d\n",ans_min,ans_max);

  return 0;
}