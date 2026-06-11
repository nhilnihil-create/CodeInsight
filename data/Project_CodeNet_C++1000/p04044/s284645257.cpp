#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main(){
   int N,L;
   cin>>N>>L;
   vector<string>S(N);
   rep(i,N){
       cin>>S[i];
   }
   sort(S.begin(),S.end());
   rep(i,N){
       cout<<S[i];
   }
   cout<<""<<endl;
}