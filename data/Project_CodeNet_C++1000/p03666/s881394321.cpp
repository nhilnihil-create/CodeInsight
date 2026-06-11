#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,a,b,c,d,k;
  cin>>n>>a>>b>>c>>d;
  k=b-a;
  bool ans=false;
  long long t=n-1;
  for(int i=0;i<n;i++){
    if(d*t-c*(n-t-1)<k)break;
    else if(c*t-d*(n-t-1)<=k){
      ans=true;
      break;
    }
    else t--;
  }
  if(ans)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
