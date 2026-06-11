#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
const int MAX_N = 200100;
int n;
ll h[MAX_N];

ll L[MAX_N],R[MAX_N];
ll st[MAX_N];

void solve(){
  
  int t = 0; 
  for(int i = 0; i < n; i++){
    while( t > 0 && h[st[t-1]] >= h[i]){ t--;}
    L[i] = t == 0 ? 0 : (st[t-1]+1);
    st[t++] = i;
  }
  
  t = 0;
  for(int i = n-1; i >= 0; i--){
    while(t > 0 && h[st[t-1]] >= h[i]){ t--;}
    R[i] = t == 0 ? n : st[t-1];
    st[t++] = i;
  }
  
  ll ans = 0;
  for(int i = 0; i < n; i++){//ここを改変する
   
   ll res = (i-L[i]+1)*(R[i]-i);
    ans += res*h[i];
  }
  
  cout << ans << endl;
}

int main(){
 
  
  cin >> n;
    
   
    for(int i = 0; i < n; i++){
      cin >> h[i]; 
    }
    
    solve();
    
  
  
  return 0;
}