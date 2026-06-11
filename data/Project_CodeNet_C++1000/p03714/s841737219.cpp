#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  long long b[n+1],c[n+1];
  b[0]=0;
  c[n]=0;
  vector<int> a(n*3);
  priority_queue<int,vector<int>,greater<int>> qb;
  priority_queue<int> qc;
  for(int i=0;i<n*3;i++){
    cin>>a[i];
    if(i<n){
      b[0]+=a[i];
      qb.push(a[i]);
    }else if(i>=n*2){
      c[n]+=a[i];
      qc.push(a[i]);
    }
  }
  for(int i=n;i<n*2;i++){
    qb.push(a[i]);
    b[i-n+1]=b[i-n]+a[i]-qb.top();
    qb.pop();
  }
  for(int i=n*2-1;i>=n;i--){
    qc.push(a[i]);
    c[i-n]=c[i-n+1]+a[i]-qc.top();
    qc.pop();
  }
  long long ma=-100000000000000000;
  for(int i=0;i<=n;i++){
    ma=max(ma,b[i]-c[i]);
  }
  cout<<ma;
}
      
    