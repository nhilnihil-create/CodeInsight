#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b,(a%b));
  }
}
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}

int main(){
  int h,w,n;
  cin>>h>>w>>n;
  int vec[h][w];
  int sum=0,sumb=0,a;
  for(int i=0;i<n;i++){
    cin>>a;
    sum+=a;
    for(int j=sumb;j<sum;j++){
      vec[j/w][j%w]=i+1;
    }
    sumb=sum;
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(i%2==1){
        cout<<vec[i][w-j-1]<<" ";
      }
      else{
        cout<<vec[i][j]<<" ";
      }
    }
    cout<<endl;
  }
}