#include<bits/stdc++.h>
using namespace std;
long long counter[100005];

int main(){
  long long n,k;
  cin>>n>>k;
  while(n--){
    int a,b;
    cin>>a>>b;
    counter[a]+=b;
  }
  long long sum = 0;
  for(int i=1; i<=100000; i++){
    sum+=counter[i];
    if(sum>=k){
      cout<<i;
      return 0;
    }
  }
}