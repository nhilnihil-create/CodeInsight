#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<long long> a(N);
  for(long long &x: a) cin>>x;
  int ans=1,start=0;
  if(N==1) {cout<<1<<endl; return 0;}
  for(int i=0;i<N-1;i++){
   if(a[i]!=a[i+1]) {start=i; break;}
    if(i=N-1) {cout<<1<<endl; return 0;}
  }
  bool sw=false,sw_1=false;
  if(a[start]<a[start+1]) sw=true;
  for(int i=start;i<N-1;i++){
    if(sw_1&&a[i]>a[i+1]){
      sw_1=false;
      sw=false;
    }
    if(sw_1&&a[i]<a[i+1]){
      sw_1=false;
      sw=true;
    }
    if(sw==true&&a[i]>a[i+1]) {
      sw_1=true;
      ans++;
    }
    else if(sw==false&&a[i]<a[i+1]){
      sw_1=true;
      ans++;
    }
  }
  cout<<ans<<endl;
}