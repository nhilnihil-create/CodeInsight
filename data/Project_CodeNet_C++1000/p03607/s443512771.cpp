#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
  int n,ans=0;cin>>n;
  ll a[n],b=0,c[n];fill(c,c+n,0);c[0]=1;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  for(int i=0;i<n-1;i++){
    if(a[i]==a[i+1]){
      c[b]++;c[b]%=2;
    }else{
      b++;
      c[b]++;
    }
  }
  for(int i=0;i<n;i++){
    if(c[i]==1){ans++;}
  }
  cout<< ans<<endl;
}
  
  