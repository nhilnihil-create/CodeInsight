#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  int N=s.size();
  int M=t.size();
  vector<int>A(N+1);A[0]=0;
  for(int i=1;i<=N;i++)
    if(s.at(i-1)=='B')
      A[i]=(A[i-1]+1)%3;
  else
    A[i]=(A[i-1]+2)%3;
  vector<int>B(M+1);B[0]=0;
  for(int i=1;i<=M;i++)
    if(t.at(i-1)=='B')
      B[i]=(B[i-1]+1)%3;
  else
    B[i]=(B[i-1]+2)%3;
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
  int a,b,c,d;cin>>a>>b>>c>>d;
    int j=(A[b]-A[a-1]-B[d]+B[c-1]+12)%3;
    if(j==0)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
   }
  return 0;
}