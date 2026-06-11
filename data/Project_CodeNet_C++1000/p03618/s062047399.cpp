#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
DPぽい

aatt
1
a
1
aa
3
aat
ata
taa

aatt
atat
taat
atta
ttaa

ababa
   ab o
  aba x
 abab o
ababa x
対称を見つける？
A^2はむり

ababaabb

aaaa
a4個=6
3+2+1
aaaaa
4+3+2+1
個数*個数-1)/2
*/
int main(){
  string S; cin>>S;
  ll ssz=S.size(), ans=1;
  vector<ll> A(26,0);
  for(ll i=0; i<ssz; i++){
    ll n=S[i]-'a';
    A[n]++;
  }
  ans+=(ssz*(ssz-1))/2;
  for(ll i=0; i<26; i++){
    ll m=(A[i]*(A[i]-1))/2;
    ans-=m;
  }
  cout<<ans<<endl;
}