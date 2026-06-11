#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

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

string S;
ll N,ans;

int main(){
  cin >> N;
  int maxCount = 0;
  ans = 1;
  for(int i=1;i<=N;i++){
    int val = i;
    int count =0;
    while(val%2==0){
      val /=2;
      count++;
    }
    if(count>maxCount){
      ans = i;
      maxCount = count;
    }
  }
  printl(ans);
}
