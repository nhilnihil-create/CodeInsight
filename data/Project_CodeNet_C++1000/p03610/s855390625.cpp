#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
  string s,t;
  int j;
  cin>>s;
  int N=s.size();
  N=(N+1)/2;
  for(int i=0;i<N;i++){
    j=2*i;
    t+=s[j];
  }
  cout<<t<<endl;
}