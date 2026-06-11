#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,c,k;
  cin >>n>>c>>k;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  int kotae=1;
  int count=0;
  int jikoku=0;
  int start=a[0];
  for(int i=0;i<n;i++){
    if(a[i]<=start+k&&count<c){
      start=min(start,a[i]);
      count++;
    }else{
      kotae++;
      count=1;
      jikoku=start+k;
      start=a[i];
    }
    //cout<<start<<" "<<jikoku<<" "<<count<<endl;
  }
  cout<<kotae<<endl;
  return 0;
}