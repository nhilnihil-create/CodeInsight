#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,a,b,ans=0;
  cin>>n>>a>>b;
  vector<long long> x(n);
  cin>>x[0];
  for(int i=1;i<n;i++){
    cin>>x[i];
    int d=x[i]-x[i-1];
    if(d*a<b){
      ans+=d*a;
    }else{
      ans+=b;
    }
  }
  cout<<ans<<endl;
}