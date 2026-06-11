#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
int X[100005];
const ll mod = 1000000007LL;
int main(){
  cin >> N;
  for(int i=0;i<N;i++) cin >> X[i];

  ll res = 1; 
  stack<int> st;
  ll cnt = 0;
  for(int i=0;i<N;i++){
    if( 2*cnt+1 <= X[i] ) {
      st.push( X[i] ); cnt++;
    } else 
      res = (res*(cnt+1LL))%mod;        
  }
  
  for(ll i=1;i<=cnt;i++)
    res = (res*i)%mod;
  cout << res << endl;
}
