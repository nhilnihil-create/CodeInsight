#include<bits/stdc++.h>
using namespace std;

int main(){
  long int n,t,s[210000];
  cin>>n>>t;
  for(int i=0;i<n;i++) cin>>s[i];
  long int sum=t+s[n-1];
  for(int i=1;i<n;i++){
    long int d=s[i]-s[i-1];
    if(d>t) sum+=t-d;
  }
  cout<<sum;
}
