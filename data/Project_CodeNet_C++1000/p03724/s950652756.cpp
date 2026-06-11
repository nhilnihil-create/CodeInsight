#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N,M;
  cin >> N >> M;
  vector<int> cnt(N,0);
  for(int i=0;i<M;i++){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    cnt.at(a)++;
    cnt.at(b)++;
  }

  for(int i=0;i<N;i++){
    if(cnt.at(i)%2!=0){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}