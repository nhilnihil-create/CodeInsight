#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int main() {
  int N,W;
  cin >> N >> W;
  vector<pair<int,int>> wv(N);
  for (int i=0; i<N; i++) {
    cin >> wv[i].first >> wv[i].second;
  }
  long smallw = wv[0].first;
  //cerr << smallw << endl;
  
  sort(wv.begin(),wv.end());
  
  /*for (int i=0; i<N; i++) {
    cerr << wv[i].first << " " << wv[i].second << endl;
  }*/
  
  int cc0 = 0;
  int cc1 = 0;
  int cc2 = 0;
  int cc3 = 0;
  for (int i=0; i<N; i++) {
    if (wv[i].first == smallw) {
      cc0++;
      continue;
    }
    if (wv[i].first == smallw+1) {
      cc1++;
      continue;
    }
    if (wv[i].first == smallw+2) {
      cc2++;
      continue;
    }
    cc3++;
  }
  
  vector<long> vv0(cc0+1,0);
  vector<long> vv1(cc1+1,0);
  vector<long> vv2(cc2+1,0);
  vector<long> vv3(cc3+1,0);
  for (int i=cc0-1; i>=0; i--) {
    vv0[cc0-i] = vv0[cc0-1-i] + wv[i].second;
    cerr << vv0[cc0-i] << ' ';
  }
  cerr << endl;
  for (int i=cc1-1; i>=0; i--) {
    vv1[cc1-i] = vv1[cc1-1-i] + wv[i+cc0].second;
    cerr << vv1[cc1-i] << ' ';
  }
  cerr << endl;
  for (int i=cc2-1; i>=0; i--) {
    vv2[cc2-i] = vv2[cc2-1-i] + wv[i+cc0+cc1].second;
    cerr << vv2[cc2-i] << ' ';
  }
  cerr << endl;
  for (int i=cc3-1; i>=0; i--) {
    vv3[cc3-i] = vv3[cc3-1-i] + wv[i+cc0+cc1+cc2].second;
    cerr << vv3[cc3-i] << ' ';
  }
  cerr << endl;
  long ans = 0;
  long term = 0;
  for(int i=0; i<cc0+1; i++) {
    for(int j=0; j<cc1+1; j++) {
      for(int k=0; k<cc2+1; k++) {
        for(int l=0; l<cc3+1; l++) {
          if ((i+j+k+l)*smallw+j+k*2+l*3 > W) {
            continue;
          }
          term = vv0[i] + vv1[j] + vv2[k] + vv3[l];
          ans = max(term,ans);
          term = 0;
        }
      }
    }
  }
  cout << ans << endl;
}