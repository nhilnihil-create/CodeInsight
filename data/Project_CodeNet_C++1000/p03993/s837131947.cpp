#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
const long long INF = 1LL << 60;

int main() {
  int N; cin>>N;
  int usagi[N+1];
  for(int i=1; i<=N; i++) cin>>usagi[i];
  int count=0;
  for(int i=1; i<=N; i++){
    if(usagi[usagi[i]]==i) count++;
  }	
  cout<<count/2<<endl;
}
