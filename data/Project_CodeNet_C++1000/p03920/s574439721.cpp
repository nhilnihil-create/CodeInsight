#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int main(){
  int n;
  scanf("%d",&n);
  int sm=0; 
  vector<int>ans;
  for(int i=1;sm+i<=n;i++){
    ans.push_back(i);
    sm+=i;
  }
  int rem=n-sm;
  for(int i=0;i<rem;i++){
    ans[int(ans.size())-1-i]++;
  }
  for(int x:ans){
    printf("%d\n",x);
  }
  return 0;
}
