#include<bits/stdc++.h>
using namespace std;

int main(){
  int l;
  cin >> l;
  vector<int> a(l * 2);
  for(int i = 0; i < l * 2; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int ans = 0;
  for(int i = 0; i < l * 2; i += 2){
    ans += min(a[i], a[i + 1]);
  }
  cout << ans << endl;
}