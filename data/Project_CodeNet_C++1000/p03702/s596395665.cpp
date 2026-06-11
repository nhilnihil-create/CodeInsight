#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N,A,B;
vector<int> H;
bool check(ll x){
  ll c=0;
  for(int i=0;i<N;i++){
    ll h = 1LL * H[i] - 1LL * x * B;
    if(h<=0) continue;
    c += h/A;
    if(h%A) c++;
  }
  return c <= x;
}

int main(){
  cin >> N >> A >> B;
  A -= B;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    H.push_back(x);
  }

  // 2分探索
  int ng=0, ok=1000000000;
  while(ng + 1 != ok){
    int x = (ng + ok) / 2;
    if(check(x)) ok = x;
    else ng = x;
  }
  cout << ok << endl;
}
