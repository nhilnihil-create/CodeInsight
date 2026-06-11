#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  int N; cin >> N;
  set<int> s;
  for(int i=0;i<N;i++){
    int x;cin >> x;
    s.insert(x);
  }

  int ans=s.size();
  if(ans%2==0) ans-=1;

  cout << ans << endl;
}