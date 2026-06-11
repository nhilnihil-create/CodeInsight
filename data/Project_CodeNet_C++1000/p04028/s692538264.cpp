#include<vector>
#include<iostream>
using namespace std;
#define df 0
typedef long int li;
const li MOD=1e9+7;

int main(){
  if(df) printf("*debug mode*\n");
  int n; cin>>n;
  string s; cin >>s;
  if(df)cout << s;
  vector<li> dp(1,1);  // N==0,|s|==0
  if(df){
    for(li x: dp)printf("%ld ",x);
    printf(":dp\n");
  }
  for(int i=1;i<=n;i++){
    //    dp.push_front(*(dp.begin()));
    dp.push_back(dp.at(i-1));
    for(int j=i-1;j>0;j--){
      dp.at(j)=dp.at(j-1);
    }
    for(int j=0;j<i-1;j++){
      (dp.at(j)+=2*dp.at(j+2))%=MOD;
    }
    if(df){
      for(li x: dp)printf("%ld ",x);
      printf(":dp[%d]\n",i);
    }
  }
  cout << *(dp.begin()+s.size());
}

/// confirm df==0 ///
