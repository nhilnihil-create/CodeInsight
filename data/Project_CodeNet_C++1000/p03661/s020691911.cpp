#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int num;
  int card;
long long summ[200020];
  long long sum=0,summin=2e9,ans,sum2;
  for(int i=0;i<N;i++){
    cin>>card;sum+=card;
    summ[i]=sum;
  }
  for(int i=0;i<N-1;i++){
    ans=sum-2*summ[i];
    if(ans<0)
      ans = -(ans);
    summin=min(summin,ans);
  }
  cout<<summin<<endl;
  return 0;
}
