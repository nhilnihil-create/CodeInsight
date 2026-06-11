#include <bits/stdc++.h>
using namespace std;

int n, a[101010];

int main(void) {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1, greater<int>() );
  for(int i = 1; i < n; i++) {
    if(a[i + 1] < i + 1) {
      int ans = a[i] - i & 1;
      int cnt = 0;
      for(int j = i + 1; a[j] == i; j++) {
	cnt ^= 1;
      }
      return puts((ans | cnt) ? "First" : "Second"), 0;
    }
  }
  puts((a[n] - n & 1) ? "First" : "Second");
}
