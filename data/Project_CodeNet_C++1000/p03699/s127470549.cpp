#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;


int main(){
  int N; cin >> N;
  int score = 0;
  vi s(N);
  rep(i,N) {cin >> s[i]; score+= s[i];}
  if(score%10 != 0) { cout << score << endl; return 0;}
  sort(all(s));
  rep(i,N){
    int sscore = score - s[i];
    if(sscore%10 != 0) { cout << sscore << endl; return 0;}
  }
  
  cout << 0 << endl;
  return 0;
}