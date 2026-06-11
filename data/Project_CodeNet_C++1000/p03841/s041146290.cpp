#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N*N,-1),B(N);
  vector<pair<int,int>> C(N);
  for(int i=0;i<N;i++){
    cin>>B[i];
    B[i]--;
    A[B[i]]=i+1;
    C[i]=make_pair(B[i],i);
  }
  sort(C.begin(),C.end());
  int n=0,m=1;
  for(int i=0;n<N;n++,m=1)
    for(;m<C[n].second+1;i++)
      if(A[i]==-1)
        A[i]=C[n].second+1,m++;
  n=N-1,m=N;
  for(int i=N*N-1;n>=0;n--,m=N)
    for(;m>C[n].second+1;i--)
      if(A[i]==-1)
        A[i]=C[n].second+1,m--;
  for(int i=1;i<=N;i++){
    int n=0,j=0;
    for(;j<N*N;j++){
      if(A[j]==i)
        n++;
      if(n==i)
        break;
    }
    if(j!=B[i-1]){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for(int i=0;i<N*N;i++){
    cout<<A[i];
    if(i==N*N-1)
      cout<<endl;
    else
      cout<<' ';
  }
}