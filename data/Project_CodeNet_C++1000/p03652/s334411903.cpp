#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,M;
ll A[305][305];
int main(){
  cin>>N>>M;
  for(ll i=0;i<N;i++)
    for(ll j=0;j<M;j++)
      cin>>A[i][j];
  ll left=0;ll right=N;
  while(1<right-left){
  ll mid=left+(right-left)/2;
    vector<ll>a(N);
    vector<bool>c(M+1,true);
    bool judge=false;
    for(ll x=0;x<M-1;x++){
      vector<ll>b(1+M);ll Max=0;ll I=0;
    for(ll i=0;i<N;i++){
    b[A[i][a[i]]]++;
      if(Max<b[A[i][a[i]]]){Max=b[A[i][a[i]]];I=A[i][a[i]];}
    }if(Max<=mid){judge=true;break;}
             c[I]=false;
          for(ll i=0;i<N;i++)
             while(!c[A[i][a[i]]])a[i]++;
       }if(judge)
            right=mid;
          else
            left=mid;
               }cout<<right<<endl;
  return 0;
}