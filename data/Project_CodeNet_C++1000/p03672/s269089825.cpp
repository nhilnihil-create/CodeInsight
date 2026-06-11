#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
string S;
  cin>>S;
  string T;
  ll N=S.size();
 for(ll i=0;i<N/2;i++) {
   S.pop_back();
   S.pop_back();
   string T;
   for(ll j=0;j<S.size()/2;j++) {
T+=S[j];
   }
   
   T+=T;
   if(T==S) {
     cout<<T.size()<<endl;
     return 0;
   }
 }
}
   
   

    