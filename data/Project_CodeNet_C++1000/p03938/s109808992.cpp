#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    A[a-1]=i;
  }
  for(int i=0;i<N;i++)cout<<(N+1)*i+1<<(i==N-1?'\n':' ');
  for(int i=0;i<N;i++)cout<<(N+1)*(N-i)+A[i]+1<<(i==N-1?'\n':' ');
}