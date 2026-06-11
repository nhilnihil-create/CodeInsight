#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
int main() {
  ll N; cin>>N;
  vector<ll> A(N);
  for(int i=0; i<N; i++) cin>>A[i];
  ll count=0;
  bool zou=1;
  bool gen=1;
  for(int i=1; i<N; i++){
    if(A[i]-A[i-1]==0) continue;
    if(A[i]-A[i-1]>0 && zou==1) gen=0;
    if(A[i]-A[i-1]<0 && gen==1) zou=0;
    if(A[i]-A[i-1]>0 && gen==1){
      count++;
      zou=1;
      gen=1;
    }
    if(A[i]-A[i-1]<0 && zou==1){
      count++;
      zou=1;
      gen=1;
    }
  }
  cout<<count+1<<endl;
}