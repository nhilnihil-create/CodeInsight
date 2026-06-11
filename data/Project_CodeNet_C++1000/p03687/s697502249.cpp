#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009


int main(){
  string s;
  cin >> s;
  int ans = INF;
  rep(i,26){
    int count = 0;
    int temp = 0;
    rep(j,s.size()){
      if(s[j] == i+97){
        temp = max(temp,count);
        count = 0;
      }
      else count++;
    }
    temp = max(temp,count);
    ans = min(ans,temp);
  }
  cout << ans << endl;
}


