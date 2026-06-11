#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main(){
   int N;
   cin>>N;
   vector<int>L(2*N);
   rep(i,2*N){
       cin>>L[i];
   }
   sort(L.rbegin(),L.rend());
   ll ans=0;
   for(int i=1; i<2*N; i+=2){
       ans+=L[i];
   }
   cout<<ans<<endl;
}