#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(){
    
   ull N,M,ans=0; cin >> N >> M;
   
   if(2*N <= M){ans += N; M-=(2*N);  ans += (M/4);}
  else{ans += (M/2);}
   cout << ans << endl;
}