#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  ll ver = 0, hol = 0;
  
  for(int i = 0;i < n;i++) cin >> a[i];
  
  sort(a.begin(), a.end(), greater<int>());
  
  for(int i = 0;i < n-1;i++){
    if(a[i] == a[i+1]){
      if(ver == 0) ver = a[i];
      else if(hol == 0) hol = a[i];
      i++;
    }
  }
  
  cout << ver * hol << endl;
}