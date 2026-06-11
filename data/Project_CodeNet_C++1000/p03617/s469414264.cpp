#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
  long long Q, H, S, D, N; cin>>Q>>H>>S>>D>>N;
  long long setQ=8*Q;
  long long setH=4*H;
  long long setS=2*S; //2Lごとの比較
  long long min1=min({setQ, setH, setS, D});
  if(min1!=D) cout<<(N*min1)/2<<endl;
  else{
    long long min2=min({setQ, setH, setS});
    long long n=N%2;
    cout<<((N-n)/2)*D+n*min2/2; 
  }
}