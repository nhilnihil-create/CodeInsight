#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long ll_MAX = 1000000000000000000;
int int_MAX = 1000000;

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
  return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main(){
  cout << setprecision(10);
  int N, Ma, Mb; 
  cin >> N >> Ma >> Mb;
  vector<int> a(N), b(N), c(N);
  for(int i = 0; i < N; i++){
    cin >> a[i] >> b[i] >> c[i];
  }

  auto dp = make_vec<int>(N, 401, 401);

  for(int i = 0; i < N; i++){
    for(int j = 0; j <= 400; j++){
      for(int k = 0; k <= 400; k++){
        dp[i][j][k] = int_MAX;
        if(j == 0 && k == 0){
          dp[i][j][k] = 0;
        }
      }
    }
  }
  dp[0][0][0] = 0;
  dp[0][a[0]][b[0]] = c[0];

  for(int i = 1; i < N; i++){
    for(int j = 0; j <= 400; j++){
      for(int k = 0; k <= 400; k++){
        if(j - a[i] >= 0 && k - b[i] >= 0){
          dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-a[i]][k-b[i]] + c[i]);
        }
        dp[i][j][k] = min(dp[i-1][j][k], dp[i][j][k]);

      }
    }
  }

  int ans = int_MAX;
  for(int i = 1; (Ma * i <= 400) && (Mb * i <= 400); i++){
    ans = min(dp[N-1][Ma*i][Mb*i], ans);
  }
  cout << (ans == int_MAX ? -1 : ans ) << endl;


}
