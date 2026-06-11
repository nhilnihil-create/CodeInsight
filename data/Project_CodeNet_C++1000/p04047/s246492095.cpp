#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define INF 100000000
using namespace std;

int main() {
 
int N,ans=0;
cin >>N;N*=2;
 vector<int> A(N);
 for(int i=0; i<N; i++){cin>>A[i];} 
// vector<vector<int>> A(N,vector<int>(M));
// for(int i=0; i<N; i++){for(int j=0; j<M; j++){cin>>A[i][j];}}
sort(A.begin(),A.end());
  for(int i=0; i<N; i++){if(i%2==0)ans+=A[i];}
cout<<ans<<endl;
}
