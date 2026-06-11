#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define MOD 1000000007

int main(){
  int n,sum=0;
  cin>>n;
  int x=1;
  while(n>sum){
    sum+=x;
    x++;
  }
  vector<int> v;
  for(int i=x-1;i>0;i--){
    if(i==n){
      v.push_back(i);
      break;
    }else if(n>i){
      n-=i;
      v.push_back(i);
    }
  }
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
  }
  return 0;
}