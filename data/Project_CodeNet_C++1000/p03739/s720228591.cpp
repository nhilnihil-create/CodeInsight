#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<long long> a(n);
  for(long long &x: a) cin>>x;
  long long ans_1=0,ans=0;
  long long sum_1=a[0],sum=a[0];
  while(sum_1<=0) {sum_1++; ans_1++;}
  while(sum>=0) {sum--; ans++;}
  for(int i=1;i<n;i++){
    sum_1+=a[i];
    if(i%2==1){
      while(sum_1>=0) {sum_1--; ans_1++;}
    }
    if(i%2==0){
      while(sum_1<=0) {sum_1++; ans_1++;}
    }
  }
  for(int i=1;i<n;i++){
    sum+=a[i];
    if(i%2==1){
      while(sum<=0) {sum++; ans++;}
    }
    if(i%2==0){
      while(sum>=0) {sum--; ans++;}
    }
  }
    cout<<min(ans_1,ans)<<endl;
}