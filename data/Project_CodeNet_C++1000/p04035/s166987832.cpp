#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, l;
  cin >> n >> l;
  vector < ll > a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  int j = 0;
  for(int i = 1; i < n; i++){
    if(a[i] + a[i + 1] >= l) j = i;
  }

  if(j == 0) cout << "Impossible\n";
  else{
    cout << "Possible\n";
    for(int i = 1; i < j; i++) cout << i << '\n';
    for(int i = n - 1; i > j; i--) cout << i << '\n';
    cout << j << '\n';
  }
}
