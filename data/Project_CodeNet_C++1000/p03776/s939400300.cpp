#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}
long long com[51][51];

int main() {
  int n, a, b;
  cin>>n>>a>>b;
  long long v[n];
  for (int i=0; i<n; i++) cin>>v[i];
  sort(v, v + n);
  reverse(v, v + n);

  com[0][0] = 1;
  for (int i=1; i<51; i++) {
    com[0][i] = 0;
  }
  for (int i=1; i<51; i++) {
    com[i][0] = 1;
    for (int j=1; j<51; j++) {
      if (j > i) {
        com[i][j] = 0;
      } else {
        com[i][j] = com[i-1][j-1] + com[i-1][j];
      }
    }
  }
  pair<long long, int> max_sum;
  long long cnt;
  for (int m=a; m<=b; m++) {
    long long sum = 0;
    for (int i=0; i<m; i++) {
      sum += v[i];
    }
    int larger = 0;
    int equal = 0;
    for (int i=0; i<n; i++) {
      if (v[i] > v[m-1]) {
        ++larger;
      } else if (v[i] == v[m-1]) {
        ++equal;
      }
    }
    if (m == a) {
      max_sum = make_pair(sum, m);
      cnt = com[equal][m-larger];
      continue;
    }
    int l = lcm(max_sum.second, m);
    if (sum * (l / m) > max_sum.first * (l / max_sum.second)) {
      max_sum = make_pair(sum, m);
      cnt = com[equal][m-larger];
    } else if (sum * (l / m) == max_sum.first * (l / max_sum.second)) {
      cnt += com[equal][m-larger];
    }
  }
  printf("%.7lf\n", 1.0 * max_sum.first / max_sum.second);
  cout<<cnt<<endl;
}