#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<numeric>
using namespace std;
#define INF (1 << 30) - 1
#define LINF 1LL << 60
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> calcNext(const string &s){
	int n = s.size();
	vector<vector<int>> res(n + 1, vector<int>(26, n)); 
	for(int i = n - 1; i >= 0; --i){
		for(int c = 0; c < 26; ++c){
			res[i][c] = res[i + 1][c]; 
			res[i][s[i] - 'a'] = i; 
		}
	}

	return res;
}

int dp[200100];

int main(){
  string a;
  cin >> a;
  int n = a.size();

  auto next = calcNext(a);
  fill((int*)dp, (int*)dp + sizeof(dp) / sizeof(int), INF);
  dp[n] = 1;
  vector<pair<char, int>> rest(n + 1, {'a', n});
  for(int i = n - 1; i >= 0; --i){
    for(int c = 0; c < 26; ++c){
      if(next[i][c] == n){
        if(dp[i] > 1){
          dp[i] = 1;
          rest[i] = {'a' + c, n};
        }
      }
      if(next[i][c] < n){
        if(dp[next[i][c] + 1] + 1 < dp[i]){
          dp[i] = dp[next[i][c] + 1] + 1;
          rest[i] = {'a' + c, next[i][c] + 1};
        }
      }
    }
  }
  
  string ans = "";
  int idx = 0;
  while(idx < n){
    auto p = rest[idx];
    ans += p.first;
    idx = p.second;
  }

  cout << ans << endl;
  return 0;
}
