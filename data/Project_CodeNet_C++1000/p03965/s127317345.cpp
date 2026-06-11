#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 100

int main(){
  string S;
  cin>>S;
  int N=S.size();
  int g_sum=0;
  int p_sum=0;
  int ans=0;
  for(int i=0;i<N;i++){
    if(g_sum==p_sum){
      if(S.at(i)=='p'){
        ans--;
      }
      g_sum++;
    }else{
      if(S.at(i)=='g'){
        ans++;
        p_sum++;
      }else{
        p_sum++;
      }
    }
  }
  cout<<ans<<endl;
}
