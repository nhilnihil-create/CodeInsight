#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  sort(a.begin(),a.end());

  vector<ll> edge(n,0);
  int k = 0;

  int cnt = 1;
  ll prev = a[0];
  for(int i=1;i<n;i++){
    if(a[i] == prev){
      cnt++;
      if(cnt==2 || cnt==4){
        edge[k++] = a[i];
      }
    }else{
      prev = a[i];
      cnt = 1;
    }
  }

  sort(edge.begin(),edge.end());

  ll ans = 0;
  ans = edge[n-1]*edge[n-2];
  cout << ans << endl;
}
