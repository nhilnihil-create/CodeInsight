#include <bits/stdc++.h>
using namespace std;
#define itn int
#define nibu(K,x) binary_search(K.begin(),K.end(),x)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define si(x) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define out(x) cout<<x<<endl
#define in(x) cin >> x
using pii = pair<int,int>;
using psi = pair<string,int>;
using pis = pair<int,string>;
using ll = long long;
using vl = vector<ll>;
using vs = vector<string>;


int main() {
 int N;
  in (N);
  vl a(N);
  rep(i,N) in(a[i]);
  int ans =0;
  rep(i,N){
   if(a[a[i]-1] == i+1) ans++ ;
    
  }
out(ans/2);	
}
  
