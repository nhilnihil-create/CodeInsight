#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;

const ll modSeed = pow(10,9) + 7;
const int INF = 1'000'000'000;

template <typename T>
vector<T> getVector(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

ll calculateDivNums(ll tg){
	ll ans = 0;
  for(ll a=1;a*a<=tg;a++){
      if(tg%a!=0){
        continue;
    }
      ans++;
      if(tg!=a*a){
        ans++;
      }
    }
  return ans;
 }   

string S;
ll N,ans;

int main(){
  ans = 0;
  cin >> N;
  for(ll a=1;a*a<=N;a++){
    if(N%a!=0) continue;
    ll b = N /a;
    ll dig = max(log10(a)+1,log10(b)+1);
    if(ans==0){
      ans = dig;
    } else{
      ans = min(dig,ans);
    }
  }
  printl(ans);
}
