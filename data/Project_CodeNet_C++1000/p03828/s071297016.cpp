#include <bits/stdc++.h>

using namespace std;

int main(){

  long long int n;
  cin>>n;
  vector<long long> cnt(n+1,1);
  long long int ans=1;
  long long int MOD=1000000007;

  for(int i=1; i<=n; i++){
    long long int index=i;
    long long int j=2;
    while(j<=index){
      if(index%j==0){
        cnt[j]+=1;
        index=index/j;
      }
      else if(index%j!=0) j++;
    }
  }

  for(int i=0; i<cnt.size(); i++){
    ans*=cnt[i];
    ans=ans%MOD;
  }

  cout<<ans<<endl;
}
