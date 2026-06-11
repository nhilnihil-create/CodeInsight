#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

int main(){
  int n;
  cin >> n;
  vll ans(1000);
  ll ANS = 1;
  for(int i = 2;i <= n;i++){
    ll num = i;
    for(int j = 2;j <= i;j++){
      if(num == 1) break;
      if(num % j == 0){
        ans[j]++;
        num /= j;
        j = 1;
      }
    }
  }
  for(int i = 2;i<= 1000;i++){
    ANS *= ans[i]+1;
    ANS %= 1000000007;
  }
  cout << ANS << endl;
}