#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using pii = pair<int, int>;
using si = set<int>;

const ll modSeed = pow(10,9) + 7;
const int INF = 100'000'000;

template <typename T>
vector<T> getVector(ll num){
    vector<T> values(num);
    for(ll i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

string S;
ll N,ans;

int main(){
  cin >> N;
  N*=3;
  auto inputs = getVector<ll>(N);
  sort(inputs.begin(),inputs.end(),greater<ll>());
  N/=3;
  N*=2;
  rep(i,N){
    if((i+1)%2==0){
      ans +=inputs[i];
    } 
  }
  printl(ans);
}
