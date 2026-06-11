#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(int i=0;i<n;i++)

int N, x;
vector<int> swap_arr(vector<int> v, int i, int j) {
  int tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
  return v;
}

int main() {
  scanf("%d %d", &N, &x);
  vector<int> v;
  if (x == 1 || x == 2*N-1) {
    printf("No\n");
  } else if (N == 2) {
    printf("Yes\n1\n2\n3\n");
  } else if (x == 2) {
    REP(i, 2*N-1) {
      if (i+1 >= x-1 && i+1 <= x+2) continue;
      v.push_back(i+1);
    }
    printf("Yes\n");
    REP(i, N-2) {
      printf("%d\n", v.back());
      v.pop_back();
    }
    printf("%d\n", x+2);
    printf("%d\n", x);
    printf("%d\n", x-1);
    printf("%d\n", x+1);
    REP(i, N-3) {
      printf("%d\n", v.back());
      v.pop_back();
    }
  } else {
    REP(i, 2*N-1) {
      if (i+1 >= x-2 && i+1 <= x+1) continue;
      v.push_back(i+1);
    }
    printf("Yes\n");
    REP(i, N-2) {
      printf("%d\n", v.back());
      v.pop_back();
    }
    printf("%d\n", x-1);
    printf("%d\n", x);
    printf("%d\n", x+1);
    printf("%d\n", x-2);
    REP(i, N-3) {
      printf("%d\n", v.back());
      v.pop_back();
    }
  }

  return 0;
}
