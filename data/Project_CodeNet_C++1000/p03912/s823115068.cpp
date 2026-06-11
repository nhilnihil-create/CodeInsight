#include<bits/stdc++.h>

using namespace std;


int main()
{
  int N, M;
  map< int, int > xs[100001];
  int sum[100001] = {};

  cin >> N >> M;

  for(int i = 0; i < N; i++) {
    int X;
    cin >> X;
    xs[X % M][X]++;
    sum[X % M]++;
  }


  int ret = sum[0] / 2;

  for(int i = 1; i <= M - i; i++) {
    if(i == M - i) {
      ret += sum[i] / 2;
      break;
    }

    int one1 = 0, one2 = 0;

    priority_queue< int > p, q;

    for(auto &a : xs[i]) {
      if(a.second / 2 > 0) p.push(a.second / 2);
      one1 += a.second % 2;
    }
    for(auto &a : xs[M - i]) {
      if(a.second / 2 > 0) q.push(a.second / 2);
      one2 += a.second % 2;
    }
    while(one1 > 0 || one2 > 0) {

      if(one1 == 0) {
        if(p.empty()) break;
        int k = p.top() - 1;
        p.pop();
        if(k > 0) p.push(k);
        one1++;
      } else {
        --one1;
      }

      if(one2 == 0) {
        if(q.empty()) break;
        int k = q.top() - 1;
        q.pop();
        if(k > 0) q.push(k);
        one2++;
      } else {
        one2--;
      }

      ++ret;
    }

    while(!p.empty()) {
      ret += p.top();
      p.pop();
    }
    while(!q.empty()) {
      ret += q.top();
      q.pop();
    }
  }
  cout << ret << endl;
}
