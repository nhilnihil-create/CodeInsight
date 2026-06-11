//includes
#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<map>
#include<queue>
#include<iomanip>
#include<numeric>
#include<assert.h>
#include<cstring>
#include<unordered_map>
#include<bitset>

//macros and consts
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define FORE(i,a) for(auto &i : a)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define accm accumulate
#define Fi first
#define Se second
#define INF 1e9
#define mINF -1e9
#define endl "\n"
#define CONT continue
#define BRK break

//shorter types
using namespace std;
using ll = long long;
using vi = std::vector<int>;
using vc = std::vector<char>;
using vll = std::vector<long long>;
//here begins your code
int N;
vll a;
signed main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> N;
  a.resize(3*N);
  REP(i,3*N){
    cin >> a[i];
  }


    vector<long long> S(N*2+1, 0);
    priority_queue<long long, vector<long long>, greater<long long> > que1;
    for (int i = 0; i < N; ++i) {
        S[i+1] = S[i] + a[i];
        que1.push(a[i]);
    }
    for (int i = N; i < N*2; ++i) {
        long long mi = que1.top();
        if (a[i] > mi) {
            S[i+1] = S[i] - mi + a[i];
            que1.pop();
            que1.push(a[i]);
        }
        else S[i+1] = S[i];
    }

 
  vector<ll> T(N * 2 + 1 ,0);
  priority_queue<ll> que2;
  for(int i = 0 ; i < N ; i++){
    T[i+1] = T[i] + a[N*3-1-i];
    que2.push(a[N*3-1-i]);
  }
  for(int i = N ; i < N * 2 ; i++){
    ll ma = que2.top();
    if(a[N*3 - i - 1] < ma){
      T[i+1] = T[i] - ma + a[N * 3 - 1 - i];
      que2.pop();
      que2.push(a[N*3 - 1 - i]);
    }
    else{
      T[i+1] = T[i];
    }
  }
 


  ll ret = -(1LL<<60);
  for(int i = N ; i <= N * 2 ; i++){
    ret = max(ret,S[i] - T[N*3 - i]);
  }
  cout << ret << endl;
  
  return 0;
}

