#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;



int main(){
  ll n;
  cin >> n;
  vector<ll>a(n),sum(n);
  for(int i=0; i<n; i++) cin >> a[i];
  sort(a.begin(),a.end());
  
  for(int i=0; i<n; i++){
    if(i==0) sum[i]=a[i];
    else sum[i]=sum[i-1]+a[i];
  }
  
  reverse(sum.begin(),sum.end());
  reverse(a.begin(),a.end());
  
  ll count=1;
  for(int i=0; i<n-1; i++){
    if(a[i]>sum[i+1]*2) break;
    count++;
  }
  
  cout << count << endl;
  
  
  
  
  
}
       
        
      
  
    