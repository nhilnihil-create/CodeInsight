#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  int count = 0;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++){
    if(a[i] % 2 != 0) count++;
  }
  cout << (count % 2 == 0 ? "YES" : "NO") << endl;
}