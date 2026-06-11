#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;



int main(){
  string s;
  cin >> s;
  ll n = s.size();
  
  ll count=0;
  ll ans=0;
  for(int i=0; i<n; i++){
    if(s[i]=='T')count++;
    else count--;
    ans = max(count,ans);
  }

  ans*=2;
  
  cout << ans << endl;
  
}
       
        
      
  
    
