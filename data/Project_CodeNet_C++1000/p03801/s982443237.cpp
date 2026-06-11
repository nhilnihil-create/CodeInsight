#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  vector<int> b;
  b.push_back(0);
  for (int i = 0; i < N; i++){
    if (a[i] > b.back()){
      b.push_back(a[i]);
    }
  }
  int b_cnt = b.size();
  vector<int> c = a;
  c.push_back(0);
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  int c_cnt = c.size();
  map<int, int> mp1;
  for (int i = 0; i < c_cnt - 1; i++){
    mp1[c[i + 1]] = c[i + 1] - c[i];
  }
  map<int, long long> mp2;
  for (int i = 0; i < N; i++){
    mp2[a[i]]++;
  }
  int sum = N;
  for (auto P : mp2){
    int tmp = sum - P.second;
    mp2[P.first] = sum;
    sum = tmp;
  }
  map<int, long long> mp3;
  for (int i = 1; i < c_cnt; i++){
    int num = *(lower_bound(b.begin(), b.end(), c[i]));
    mp3[num] += mp1[c[i]] * mp2[c[i]];
  }
  for (int i = 0; i < N; i++){
    cout << mp3[a[i]] << endl;
    mp3[a[i]] = 0;
  }
}