#include <bits/stdc++.h>

using namespace std;
long long change_num(long long p[], int N) {
  long long res = 0;
  long long next_sum;
  long long sum = p[0];
  for (int i = 1; i < N; i++) {
    next_sum = sum + p[i];
    if((sum < 0 && next_sum > 0) || (sum > 0 && next_sum < 0)) {
      sum = next_sum;
      continue;
    } 
    if(sum > 0 && next_sum >= 0) {
      res += next_sum + 1;
      sum = -1;
      continue;
    }
    if (sum < 0 && next_sum <= 0) {
      res += 1 - next_sum;
      sum = 1;
      continue;
    }
  }
  return res;
}


int main() {
  int N;
  cin >> N;
  
  long long a[N];
  for (int i = 0; i < N; i++)
    cin >> a[i];
    
  long long ans = 0;
  long long sum = a[0];
  
  long long plus_ans = 0;
  long long minus_ans = 0;
  if (a[0] == 0) {
    plus_ans = 1; 
    a[0] = 1;
    plus_ans += change_num(a, N); 
 
    minus_ans = 1;
    a[0] = -1;
    minus_ans += change_num(a, N);
  } else if (a[0] > 0) {
    plus_ans = 0; 
    plus_ans += change_num(a, N); 
 
    minus_ans = 1 + a[0];
    a[0] = -1;
    minus_ans += change_num(a, N);
    
  } else {
    minus_ans = 0;
    minus_ans += change_num(a, N);
    
    plus_ans = 1 - a[0]; 
    a[0] = 1;
    plus_ans += change_num(a, N); 
 
  }

    
  if(plus_ans < minus_ans) {
    ans = plus_ans;
  } else {
    ans = minus_ans;
  }  
  cout << ans << endl;

}