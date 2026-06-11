#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,mx=0;
  cin>>n;
  vector<int>l(n);
  vector<int>r(n);
  for(int i=0;i<n;i++){
    cin>>l[i]>>r[i];
  }
  for(int i=0;i<n;i++){
    mx+=r[i]-l[i]+1;
  }
  cout<<mx<<endl;
}
