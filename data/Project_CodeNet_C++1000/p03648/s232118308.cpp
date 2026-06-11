#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAX 55

int K;
int ans[MAX];

signed  main(){

  cin>>K;

  cout<<50<<endl;

  for(int i = 0; i < 50; i++){
    ans[i] += i+K/50;
    if(49-i < K%50) ans[i]++;
  }
  for(int i = 0; i < 50; i++){
    if(i)cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;

  return 0;
}
