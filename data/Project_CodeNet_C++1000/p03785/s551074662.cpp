#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,c,k;
  cin >> n >> c >> k;
  vector<long long> t(n);
  long long ans = 0;
  for(long long i = 0; i < n; i++){
    cin >> t[i];
  }
  sort(t.begin(),t.end());
  long long kousin = t[0]+k;
  long long kyaku = 0;  
  for(long long i = 0; i < n; i++){
    if(t[i] <= kousin && (kyaku + 1) <= c){
      kyaku++;
    }else{
      ans++;
      kousin = t[i]+k;
      kyaku = 1;
    }
  }
  if(kyaku > 0) ans++;
  cout << ans << endl;
}