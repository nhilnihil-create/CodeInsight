#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  string s1, s2;
  cin >>s1 >> s2;
  ll ans=1;
  int prestate=0;
  rep(i, n){
    if(s1[i]==s2[i]){
      if(prestate==0){
        ans*=3;
      } else if(prestate==1){
        ans*=2;
      }
      ans%=mod;
      prestate=1;
    } else {
      i++;
      if(prestate==0){
        ans*=6;
      } else if(prestate==1){
        ans*=2;
      } else if(prestate==2){
        ans*=3;
      }
      ans%=mod;
      prestate=2;
    }
  }
  cout << ans << endl;
  return 0;
}
