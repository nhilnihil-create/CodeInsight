#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,K,length=0;
  cin>>N>>K;
  int l[N];
  for (int i = 0; i < N; i++) {
    cin>>l[i];
    length+=l[i];
  }
  sort(l,l+N);
  for (int i = 0; i < N-K; i++) {
    length-=l[i];
  }
  cout<<length;
}