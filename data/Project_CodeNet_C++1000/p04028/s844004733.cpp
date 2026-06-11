#include <iostream>

using namespace std;

int const nmax = 5000;
int const lgmax = 12;
int const modulo = 1000000007;
int cat[5 + nmax];

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

void computecat(){
  cat[0] = 1;
  for(int i = 1;i <= nmax; i++)
    for(int j = 0; j < i; j++) {
      cat[i] += 1LL * cat[j] * cat[i - 1 - j] % modulo;
      if(modulo <= cat[i])
        cat[i] -= modulo;
    }

}
int empt[5 + nmax][5 + nmax];
int dp[1 + nmax], dp2[1 + nmax];
int far[1 + lgmax][1 + nmax];

void computefar(int n, int spaces){
  for(int i = 0;i <= n; i++)
    far[0][i] = cat[i];
  for(int h = 1;h <= lgmax; h++)
    for(int i = 0;i <= n; i++)
      for(int j = 0;j <= n - i; j++)
        if(i + j <= n) {
          far[h][i + j] += 1LL * far[h - 1][i] * far[h - 1][j] %modulo;
          if(modulo <= far[h][i + j])
            far[h][i + j] -= modulo;
        }
  dp[0] = 1;
  for(int h = lgmax; 0 <= h; h--)
    if(0 < ((1 << h) & spaces)) {
      for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n - i; j++)
          if(i + j <= n) {
            dp2[i + j] += 1LL * dp[i] * far[h][j] % modulo;
            if(modulo <= dp2[i + j])
              dp2[i + j] -= modulo;
          }

      for(int i = 0; i <= n; i++) {
        dp[i] = dp2[i];
        dp2[i] = 0;
      }
    }
}

int main()
{
  int n,k;
  string s;
  cin >> n >> s;
  k = s.size();
  computecat();
  empt[0][0] = 1;
  for(int i = 1;i <= n; i++) {
    empt[i][0] = (empt[i - 1][0] + empt[i - 1][1]) % modulo;
    for(int j = 1; j <= i; j++)
      empt[i][j] = (empt[i - 1][j + 1] + 1LL * 2 * empt[i - 1][j - 1]) % modulo;
  }
  int result = 0;
  int lost = n - k;
  computefar(lost, k);


  for(int i = 0; i <= lost; i++){
    if((lost - i) % 2 == 0) {
      result += 1LL * empt[i][0] * dp[(lost - i) / 2] % modulo * lgpow(2, (lost - i) / 2) % modulo;
    }
    if(modulo <= result)
      result -= modulo;
  }
  cout << result << '\n';
  return 0;
}
