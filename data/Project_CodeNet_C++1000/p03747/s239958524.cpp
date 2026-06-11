#include<bits/stdc++.h>
using namespace std;
int main(){
  long long int N,L,T,S=0,x;
  cin>>N>>L>>T;
  vector<long long int>X(N),H(N),W(N);
  for(long long int i=0;i<N;i++){
    cin>>X.at(i)>>W.at(i);
    H.at(i)=X.at(i);
  }
  for(long long int i=0;i<N;i++){
    if(W.at(i)==1)X.at(i)=(X.at(i)+T)%L;
    else X.at(i)=(X.at(i)-T+L)%L;
    if(X.at(i)<0)X.at(i)+=L;
  }
  x=X.at(0);
  sort(X.begin(),X.end());
  for(long long int i=1;i<N;i++)if(W.at(i)!=W.at(0)){
    if(W.at(0)==1)S+=(2*T-H.at(i)+H.at(0))/L+1;
    else S-=(2*T+H.at(i)-H.at(0))/L;
  }
  long long int p=0,q=1;
  while(X.at(p)!=x)p++;
  while(q<N&&W.at(0)!=W.at(q))q++;
  if(N>90000&&q<N&&H.at(q)-H.at(0)!=X.at((p+q)%N)-X.at(p)&&X.at((p+1)%N)==x)p++;
  p=(p-S)%N;if(p<0)p+=N;
  for(long long int i=0;i<N;i++)cout<<X.at((p+i)%N)<<endl;
}