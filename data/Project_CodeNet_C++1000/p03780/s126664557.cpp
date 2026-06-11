#include<bits/stdc++.h>
using namespace std;
int main(){
int N,K;
  cin>>N>>K;
  vector<int64_t>a(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
  int64_t sum=0;
  for(int i=0;i<N;i++)
    sum+=a.at(i);
  if(sum<K)
    cout<<N<<endl;
  else{
  a.push_back(0);
    sort(a.begin(),a.end());
    int left=0;int right=N;
    while(1<right-left){
      int mid=left+(right-left)/2;
      vector<int64_t>B(N+1);
      for(int i=0;i<=N;i++)
        B.at(i)=a.at(i);
      B.erase(B.begin()+mid);
      vector<vector<bool>>dp(N+1,vector<bool>(K,false));
      dp[0][0]=true;
      for(int i=1;i<=N;i++){
      for(int j=0;j<K;j++){
      if(j<B.at(i-1))
        dp[i][j]=dp[i-1][j];
        else
          dp[i][j]=(dp[i-1][j] ||dp[i-1][j-B.at(i-1)]);
      }
      }int64_t A;
      for(int j=K-1;0<=j;j--){
      if(dp[N][j]){A=j;break;}
      
      }if(K<=A+a.at(mid))
        right=mid;
      else
        left=mid;
      
      }cout<<left<<endl;
     }
    return 0;
}